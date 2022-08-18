class Solution {
public:
    bool isRobotBounded(string instructions) {
        int n = instructions.length();
        
        int x = 0 , y = 0;
        int dir[4][2] = {{0,1} , {-1, 0} , {0 , -1} , {1 , 0}};
        int j = 0;
        for(int i = 0;i<n;i++){
            if(instructions[i] == 'G'){
                x += dir[j][0];
                y += dir[j][1];
            }else if(instructions[i] == 'L'){
                j = (j + 1)%4;
            }else{
                j = (j + 3)%4;
            }
        }
        
        return (x  == 0 && y == 0) || j > 0;
    }
};