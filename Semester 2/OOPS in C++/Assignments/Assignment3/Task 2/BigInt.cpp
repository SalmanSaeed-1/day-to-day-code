#include "BigInt.h"

// ─── private helpers ──────────────────────────────────────────────────────────

int BigInt::strLen(const char* s) {
    int i = 0;
    while (s && s[i] != '\0') i++;
    return i;
}

void BigInt::fromInt(int val) {
    negative = (val < 0);
    long long v = (val < 0) ? -(long long)val : (long long)val;
    if (v == 0) {
        numDigits = 1;
        digits    = new int[1];
        digits[0] = 0;
        return;
    }
    long long tmp = v;
    int cnt = 0;
    while (tmp > 0) { cnt++; tmp /= 10; }
    numDigits = cnt;
    digits    = new int[numDigits];
    for (int i = 0; i < numDigits; i++) { digits[i] = (int)(v % 10); v /= 10; }
}

void BigInt::fromString(const char* text) {
    int len   = strLen(text);
    int start = 0;
    negative  = false;
    if (len > 0 && text[0] == '-') { negative = true;  start = 1; }
    else if (len > 0 && text[0] == '+') { start = 1; }
    while (start < len - 1 && text[start] == '0') start++;
    numDigits = len - start;
    if (numDigits <= 0) {
        numDigits = 1; digits = new int[1]; digits[0] = 0; negative = false; return;
    }
    digits = new int[numDigits];
    for (int i = 0; i < numDigits; i++)
        digits[i] = text[len - 1 - i] - '0';
}

void BigInt::trim() {
    while (numDigits > 1 && digits[numDigits - 1] == 0) numDigits--;
    if (numDigits == 1 && digits[0] == 0) negative = false;
}

BigInt& BigInt::assign(const BigInt& other) {
    if (this != &other) {
        delete[] digits;
        numDigits = other.numDigits;
        negative  = other.negative;
        digits    = new int[numDigits];
        for (int i = 0; i < numDigits; i++) digits[i] = other.digits[i];
    }
    return *this;
}

int BigInt::compareMagnitude(const BigInt& a, const BigInt& b) {
    if (a.numDigits != b.numDigits)
        return (a.numDigits > b.numDigits) ? 1 : -1;
    for (int i = a.numDigits - 1; i >= 0; i--)
        if (a.digits[i] != b.digits[i])
            return (a.digits[i] > b.digits[i]) ? 1 : -1;
    return 0;
}

// Both operands treated as positive; sign set by caller
BigInt BigInt::addMagnitude(const BigInt& a, const BigInt& b) {
    int sz    = ((a.numDigits > b.numDigits) ? a.numDigits : b.numDigits) + 1;
    int* buf  = new int[sz];
    int  carry = 0;
    for (int i = 0; i < sz; i++) {
        int da  = (i < a.numDigits) ? a.digits[i] : 0;
        int db  = (i < b.numDigits) ? b.digits[i] : 0;
        int sum = da + db + carry;
        buf[i]  = sum % 10;
        carry   = sum / 10;
    }
    // Build result bypassing default constructor side-effects
    BigInt result;           // calls fromInt(0) → digits = new int[1]
    delete[] result.digits;
    result.digits    = buf;
    result.numDigits = sz;
    result.negative  = false;
    result.trim();
    return result;
}

// Requires |a| >= |b|; sign set by caller
BigInt BigInt::subMagnitude(const BigInt& a, const BigInt& b) {
    int* buf   = new int[a.numDigits];
    int  borrow = 0;
    for (int i = 0; i < a.numDigits; i++) {
        int da   = a.digits[i];
        int db   = (i < b.numDigits) ? b.digits[i] : 0;
        int diff = da - db - borrow;
        if (diff < 0) { diff += 10; borrow = 1; } else borrow = 0;
        buf[i]   = diff;
    }
    BigInt result;
    delete[] result.digits;
    result.digits    = buf;
    result.numDigits = a.numDigits;
    result.negative  = false;
    result.trim();
    return result;
}

// ─── constructors / destructor ────────────────────────────────────────────────

BigInt::BigInt(int val) : digits(nullptr), numDigits(0), negative(false) {
    fromInt(val);
}

BigInt::BigInt(const char* text) : digits(nullptr), numDigits(0), negative(false) {
    fromString(text);
}

BigInt::BigInt(const BigInt& copy) : numDigits(copy.numDigits), negative(copy.negative) {
    digits = new int[numDigits];
    for (int i = 0; i < numDigits; i++) digits[i] = copy.digits[i];
}

BigInt& BigInt::operator=(const BigInt& other) {
    return assign(other);
}

BigInt::~BigInt() {
    delete[] digits;
    digits = nullptr;
}

// ─── arithmetic ───────────────────────────────────────────────────────────────

BigInt BigInt::operator+(const BigInt& val) const {
    BigInt result(0);
    if (negative == val.negative) {
        BigInt tmp = addMagnitude(*this, val);
        result.assign(tmp);
        result.negative = negative;
    } else {
        int cmp = compareMagnitude(*this, val);
        if (cmp == 0) {
            // already 0
        } else if (cmp > 0) {
            BigInt tmp = subMagnitude(*this, val);
            result.assign(tmp);
            result.negative = negative;
        } else {
            BigInt tmp = subMagnitude(val, *this);
            result.assign(tmp);
            result.negative = val.negative;
        }
    }
    if (result.numDigits == 1 && result.digits[0] == 0) result.negative = false;
    return result;
}

BigInt BigInt::operator+(int val) const { return *this + BigInt(val); }

BigInt BigInt::operator-(const BigInt& val) const {
    BigInt neg(val);
    if (!(val.numDigits == 1 && val.digits[0] == 0))
        neg.negative = !val.negative;
    return *this + neg;
}

BigInt BigInt::operator-(int val) const { return *this - BigInt(val); }

BigInt BigInt::operator*(const BigInt& val) const {
    int   totalLen = numDigits + val.numDigits;
    int*  buf      = new int[totalLen];
    for (int i = 0; i < totalLen; i++) buf[i] = 0;
    for (int i = 0; i < numDigits; i++) {
        int carry = 0;
        for (int j = 0; j < val.numDigits; j++) {
            int prod   = digits[i] * val.digits[j] + buf[i + j] + carry;
            buf[i + j] = prod % 10;
            carry      = prod / 10;
        }
        if (carry) buf[i + val.numDigits] += carry;
    }
    BigInt result(0);
    delete[] result.digits;
    result.digits    = buf;
    result.numDigits = totalLen;
    result.negative  = (negative != val.negative);
    result.trim();
    if (result.numDigits == 1 && result.digits[0] == 0) result.negative = false;
    return result;
}

// ─── compound assignment ──────────────────────────────────────────────────────

BigInt BigInt::operator+=(const BigInt& rhs) { assign(*this + rhs); return *this; }
BigInt BigInt::operator-=(const BigInt& rhs) { assign(*this - rhs); return *this; }
BigInt BigInt::operator*=(const BigInt& rhs) { assign(*this * rhs); return *this; }

// ─── comparison ───────────────────────────────────────────────────────────────

bool BigInt::operator==(const BigInt& val) const {
    if (negative != val.negative) return false;
    if (numDigits != val.numDigits) return false;
    for (int i = 0; i < numDigits; i++)
        if (digits[i] != val.digits[i]) return false;
    return true;
}

bool BigInt::operator==(const char* val) const { return *this == BigInt(val); }
bool BigInt::operator!=(const BigInt& val) const { return !(*this == val); }

bool BigInt::operator<(const BigInt& val) const {
    if (negative && !val.negative) return true;
    if (!negative && val.negative) return false;
    int cmp = compareMagnitude(*this, val);
    return negative ? (cmp > 0) : (cmp < 0);
}

bool BigInt::operator<=(const BigInt& val) const { return !(val < *this); }
bool BigInt::operator>(const BigInt& val) const  { return val < *this; }
bool BigInt::operator>=(const BigInt& val) const { return !(*this < val); }

// ─── unary ────────────────────────────────────────────────────────────────────

BigInt& BigInt::operator++()    { assign(*this + BigInt(1)); return *this; }
BigInt  BigInt::operator++(int) { BigInt old(*this); assign(*this + BigInt(1)); return old; }
BigInt& BigInt::operator--()    { assign(*this - BigInt(1)); return *this; }
BigInt  BigInt::operator--(int) { BigInt old(*this); assign(*this - BigInt(1)); return old; }

// ─── conversion ───────────────────────────────────────────────────────────────

BigInt::operator int() const { return numDigits; }

// ─── output helper ───────────────────────────────────────────────────────────

char* BigInt::toCharArray() const {
    int   len = numDigits + (negative ? 1 : 0);
    char* buf = new char[len + 1];
    int   idx = 0;
    if (negative) buf[idx++] = '-';
    for (int i = numDigits - 1; i >= 0; i--) buf[idx++] = '0' + digits[i];
    buf[idx] = '\0';
    return buf;
}

// ─── stream operators ────────────────────────────────────────────────────────

ostream& operator<<(ostream& output, const BigInt& val) {
    char* s = val.toCharArray();
    output << s;
    delete[] s;
    return output;
}

istream& operator>>(istream& input, BigInt& val) {
    char buf[1001];
    input >> buf;
    BigInt tmp(buf);
    val.assign(tmp);
    return input;
}
