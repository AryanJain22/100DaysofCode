struct Node {
    int vertex;
    Node* next;
};

class Solution { 
public:
    static Node* insert(Node* head, int val) {
        Node* q = new Node();
        q->vertex = val;
        q->next = head;
        return q;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination)
            return true;
        
        // Construct adjacency lists using n linked lists
        Node** adj_map = new Node*[n];
        for (int i = 0; i < n; i++) {
            adj_map[i] = nullptr;
        }

        for (int i = 0; i < edges.size(); i++) {
            adj_map[edges[i][0]] = insert(adj_map[edges[i][0]], edges[i][1]);
            adj_map[edges[i][1]] = insert(adj_map[edges[i][1]], edges[i][0]);
        }

        // Search
        int* visited = new int[n]; // Record whether the node has been visited
        for (int i = 0; i < n; i++)
            visited[i] = 0;
        int* stk = new int[n];
        int top = -1;
        int* stk_exist = new int[n]; // Record whether the node is in the stk
        for (int i = 0; i < n; i++)
            stk_exist[i] = 0;
        
        // Search from the source
        stk[++top] = source;
        stk_exist[source] = 1;
        while (top != -1) {
            if (visited[stk[top]] == 0) {
                int temp = stk[top];
                stk_exist[temp] = 0;
                top--;
                Node* adj = adj_map[temp];
                while (adj != nullptr) {
                    if (adj->vertex == destination)
                        return true;
                    if (visited[adj->vertex] == 0 && stk_exist[adj->vertex] == 0) {
                        stk[++top] = adj->vertex;
                        stk_exist[adj->vertex] = 1;
                    }
                    adj = adj->next;
                }
                visited[temp] = 1;
            } else {
                stk_exist[stk[top]] = 0;
                top--;
            }
        }
        return visited[destination] == 1;
    }
};