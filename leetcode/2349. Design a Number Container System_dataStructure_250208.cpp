class NumberContainers {
    unordered_map<int, multiset<int>> container;
    unordered_map<int, int> array;
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if(array.count(index)){
            int prevNum = array[index];
            container[prevNum].erase(index);

            if(container[prevNum].size() == 0){
                container.erase(prevNum);
            }
        }
        array[index] = number;
        container[number].insert(index);
    }
    
    int find(int number) {
        if(!container.count(number)) return -1;
        return *container[number].begin();
    }
};