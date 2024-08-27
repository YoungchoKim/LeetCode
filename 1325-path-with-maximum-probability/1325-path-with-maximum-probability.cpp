struct Node{
    int nod;
    double prob;
};
struct QNode{
    int nod;
    double probSum;
};
class Solution {
public:
    vector<Node> v[10001];
    double visited[10001] = {0};
    queue<QNode> q;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        double ans = 0;
        for(int i = 0 ; i < edges.size();i++){
            double prob = succProb[i];
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back({b, prob});
            v[b].push_back({a, prob});
        }
        visited[start_node] = 1;
        q.push({start_node, 1});
        while(!q.empty()){
            QNode nod = q.front();
            q.pop();
            if (nod.nod == end_node){
                if(ans < nod.probSum){
                    ans = nod.probSum;
                }
            }
            for(int i = 0 ; i < v[nod.nod].size(); i++){
                Node nextNod = v[nod.nod][i];
                if(nextNod.nod != end_node && visited[nextNod.nod] >= nod.probSum * nextNod.prob){
                    continue;
                }
                if (visited[nextNod.nod] < nod.probSum * nextNod.prob){
                    visited[nextNod.nod] = nod.probSum * nextNod.prob;
                }
                q.push({nextNod.nod, nod.probSum * nextNod.prob});
            }
        }
        return ans;

    }
};