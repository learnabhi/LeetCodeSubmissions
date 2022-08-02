class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>degrees(n+1);
        
        for (auto road : roads) {
            degrees[road[0]]++;
            degrees[road[1]]++;
        }
        int firstMax = 0, secondMax = 0;
        for (int degree : degrees)
        {
            if (degree > firstMax)
            {
                secondMax = firstMax;
                firstMax =  degree;
            }
            else if (degree > secondMax && degree < firstMax)
            {
                secondMax = degree;
            }
        }
        int fmCount = 0, smCount = 0;
        for (int degree : degrees)
        {
            if (degree == firstMax) fmCount++;
            if (degree == secondMax) smCount++;
        }

        if (fmCount > 1)
        {
            int edgeCount = 0;
            for (auto road : roads)
                if (degrees[road[0]] == firstMax && degrees[road[1]] == firstMax) edgeCount++;

            int maxEdgeWithFirstMax = fmCount * (fmCount-1) / 2;
            return 2 * firstMax - (maxEdgeWithFirstMax == edgeCount ? 1 : 0);
        }
        
            int edgeCount = 0;
            for (auto road : roads)
            {
                if (degrees[road[0]] == firstMax && degrees[road[1]] == secondMax) edgeCount++;
                if (degrees[road[0]] == secondMax && degrees[road[1]] == firstMax) edgeCount++;
            }
            return firstMax + secondMax - (smCount == edgeCount ? 1 : 0); 
    }
};