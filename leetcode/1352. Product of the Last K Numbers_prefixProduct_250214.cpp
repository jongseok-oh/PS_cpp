class ProductOfNumbers {
    vector<int> prefixProducts = {1};
public:
    ProductOfNumbers() {}
    
    void add(int num) {
        if(num == 0) {
            prefixProducts = {1};
            return;
        }
        prefixProducts.push_back(num);
        int n = prefixProducts.size();
        prefixProducts[n-1] *= prefixProducts[n-2];
    }
    
    int getProduct(int k) {
        int n = prefixProducts.size();
        if(n <= k) return 0;
        return prefixProducts[n-1] / prefixProducts[n-k-1];
    }
};