//OM NAMO NARAYANA
//https://leetcode.com/problems/reaching-points/submissions/

class Solution {
public:
    
    void slowstart(int sx, int sy, int &tx, int &ty){
        int count = 1;
        if(tx < ty){
            while(tx < ty && ty >= sy){
                ty -= tx*count;
                count *= 2;
            }
            count /=2;
            ty += tx*count;
        }else{
            while(ty < tx && tx >= sx){
                tx -= ty*count;
                count *= 2;
            }
            count /=2;
            tx += ty*count;
        }
        return;
    }
    
    bool recur(int sx, int sy, int tx, int ty){
        if(sx>tx || sy > ty)return false;
        if(sx==tx && (ty-sy)%sx == 0)return true;
        if(sy==ty && (tx-sx)%sy == 0)return true;
        if(tx > ty){
            if(tx%ty > sx)tx%=ty;
            else tx -= ty;  
        }else{
            if(ty%tx > sy)ty%=tx;
            else ty -= tx;
        }
        return recur(sx, sy, tx, ty);
    }
    
    
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        slowstart(sx, sy, tx, ty);
        return recur(sx, sy, tx, ty);
        
        
    }
};