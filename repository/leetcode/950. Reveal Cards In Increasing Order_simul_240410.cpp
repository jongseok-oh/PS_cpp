class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        queue<int> q;
        for(int i = 0; i<n; ++i) q.push(i);

        sort(deck.begin(), deck.end());
        vector<int> revealCards(n);

        for(int i = 0; i<n; ++i){
            int order = q.front(); q.pop();
            revealCards[order] = deck[i];

            if(q.size()){
                order = q.front(); q.pop();
                q.push(order);
            }
        }

        return revealCards;
    }
};