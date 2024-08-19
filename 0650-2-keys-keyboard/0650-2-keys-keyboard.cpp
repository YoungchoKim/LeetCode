struct Node{
    int actionCnt;
    int copiedCnt;
    int aCnt;
};

class Solution {
public:
    queue<Node> que;
    bool visited[2001][2001];
    int minSteps(int n) {
        que.push({0, 0, 1});
        visited[0][1] = true;
        while(!que.empty()){
            Node nod = que.front();
            que.pop();
            if (nod.aCnt == n){
                return nod.actionCnt;
            }
            int nextCopied = nod.aCnt;
            int nextAcnt = nod.aCnt + nod.copiedCnt;
            if (nextCopied <= 1000 && !visited[nextCopied][nod.aCnt]){
                visited[nextCopied][nod.aCnt] = true;
                que.push({nod.actionCnt + 1,nextCopied, nod.aCnt });
            }
            if (nextAcnt <= 1000 && !visited[nod.copiedCnt][nextAcnt]){
                visited[nod.copiedCnt][nextAcnt] = true;
                que.push({nod.actionCnt + 1,nod.copiedCnt, nextAcnt });
            }
        }
        return 0;
    }
};