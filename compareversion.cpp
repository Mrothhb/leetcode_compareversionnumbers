class Solution {
public:
    int compareVersion(string version1, string version2) {

    std::string delimiter = ".";
    vector<int> v_version1;
    vector<int> v_version2;
    int temp = 0;
    int iterations = 0;

    size_t pos = 0;
    std::string token;
        
    while ((pos = version1.find(delimiter)) != std::string::npos) {
        token = version1.substr(0, pos);
        stringstream v1(token); 
        // The object has the value 12345 and stream 
        // it to the integer x 
        v1 >> temp; 
        v_version1.push_back(temp);
        version1.erase(0, pos + delimiter.length());
    }
        stringstream v1(version1);
        v1 >> temp;
        v_version1.push_back(temp);
        
    while ((pos = version2.find(delimiter)) != std::string::npos) {
        token = version2.substr(0, pos);
        stringstream v2(token); 
        // The object has the value 12345 and stream 
        // it to the integer x 
        v2 >> temp; 
        v_version2.push_back(temp);
        version2.erase(0, pos + delimiter.length());
    }
        stringstream v2(version2);
        v2 >> temp;
        v_version2.push_back(temp);
        
    if(v_version1.size() > v_version2.size()){
        iterations = v_version1.size();
        v_version2.resize(v_version1.size(), 0);
    }else if(v_version2.size() > v_version1.size()){        
        iterations = v_version2.size();
        v_version1.resize(v_version2.size(), 0);
    }else{
        iterations = v_version1.size();
    }
        
    for(int i = 0; i < iterations; i++){
        if(v_version1[i] > v_version2[i]){
            return 1;
        }
        if(v_version1[i] < v_version2[i]){
            return -1;
        }
        
    } 
    return 0;
        
    }
};
