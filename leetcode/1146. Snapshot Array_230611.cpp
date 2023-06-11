class SnapshotArray {

    struct version{int snap_id, val;};

    vector<vector<version>> vec;

    int snapCnt;

public:
    SnapshotArray(int length) {
        vec = vector<vector<version>> (length, vector<version> (1, {0,0}));
        snapCnt = 0;
    }
    
    void set(int index, int val) {
        if(vec[index].back().snap_id == snapCnt)
            vec[index][vec[index].size()-1].val = val;
        else vec[index].push_back({this->snapCnt, val});
    }
    
    int snap() {
        this->snapCnt++; return this->snapCnt - 1;
    }
    
    int get(int index, int snap_id) {
        vector<version>& versions = vec[index];
        int low = 0, high = versions.size();

        while(low + 1 < high){
            int mid = (low + high) >>1;

            if(versions[mid].snap_id > snap_id) high = mid;
            else low = mid;
        }

        return vec[index][low].val;
    }
};