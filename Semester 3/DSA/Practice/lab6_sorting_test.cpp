#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
#include <vector>

#include "lab6_sorting.cpp"

int main(int argc, char**){
    if(argc>1){
        insertion_sort_ll(nullptr);
        return 0;
    }
    std::vector<std::vector<int>> cases = {
        {}, {1}, {1,2}, {2,1}, {2,1,3,6,4}, {1,2,3,4,5},
        {5,4,3,2,1}, {7,7,7}, {3,1,3,2,1}, {-3,0,-5,2,-1},
        {INT_MAX,0,INT_MIN,INT_MAX,INT_MIN}
    };
    std::mt19937 generator(42);
    for(int t=0; t<1000; ++t){
        std::vector<int> input(generator()%51);
        for(int& value: input) value = int(generator()%41)-20;
        cases.push_back(input);
    }
    using ArraySort = void (*)(int*, int);
    ArraySort arrays[] = {bubble_sort_array, selection_sort_array, insertion_sort_array};
    const char* array_names[] = {"bubble_sort_array", "selection_sort_array", "insertion_sort_array"};
    using ListSort = void (*)(Node*);
    ListSort lists[] = {bubble_sort_ll, selection_sort_ll, insertion_sort_ll};
    const char* list_names[] = {"bubble_sort_ll", "selection_sort_ll", "insertion_sort_ll"};
    for(int s=0; s<3; ++s){
        int failures = 0;
        for(auto input: cases){
            auto expected = input;
            std::sort(expected.begin(), expected.end());
            arrays[s](input.data(), int(input.size()));
            if(input!=expected) ++failures;
        }
        std::cout << array_names[s] << ": " << failures << " failures / " << cases.size() << " cases\n";
    }
    for(int s=0; s<3; ++s){
        int failures = 0, skipped = 0;
        for(auto input: cases){
            auto expected = input;
            std::sort(expected.begin(), expected.end());
            std::vector<Node> nodes(input.size());
            for(size_t i=0; i<input.size(); ++i){
                nodes[i] = {input[i], i+1<input.size()? &nodes[i+1]:nullptr};
            }
            Node* head = nodes.empty()? nullptr:&nodes[0];
            lists[s](head);
            std::vector<int> actual;
            Node* current = head;
            bool links_ok = true;
            for(size_t i=0; i<nodes.size(); ++i){
                if(current!=&nodes[i]){ links_ok = false; break; }
                actual.push_back(current->data);
                current = current->next;
            }
            if(current!=nullptr) links_ok = false;
            if(actual!=expected || !links_ok){
                if(failures++==0){
                    std::cout << list_names[s] << " first failing input:";
                    for(int value:input) std::cout << ' ' << value;
                    std::cout << " ->";
                    for(int value:actual) std::cout << ' ' << value;
                    std::cout << '\n';
                }
            }
        }
        std::cout << list_names[s] << ": " << failures << " failures / " << cases.size()-skipped
                  << " cases (" << skipped << " empty cases skipped)\n";
    }
}
