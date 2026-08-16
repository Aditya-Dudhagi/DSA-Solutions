class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int xt = target[0], yt = target[1];
        int minInd = -1;
        int prevman = INT_MAX;
        for(int i=0; i<drones.size(); i++){
            int xi = drones[i][0], yi = drones[i][1], range = drones[i][2];
            int manhat = abs(xi-xt) + abs(yi-yt);

            if(manhat <= range){
                if(manhat < prevman) {
                    cout<<"Initially prevman: "<<prevman<<endl;
                    prevman = manhat;
                    minInd = i; 
                    cout<<minInd<<" is updated\n with prevman "<<prevman<<endl;
                } else if(manhat == prevman) continue;
            }
        }
        return minInd ;
    }
};