class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        int arrived = arrivalTime + delayedTime;
        if(arrived >= 24){
            arrived = arrived -24;
        }
        return arrived;
    }
};