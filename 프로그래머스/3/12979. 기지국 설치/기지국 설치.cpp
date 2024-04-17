#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    for(int i = 0; i <= stations.size(); i++){
        // 전파가 닿지 않는 아파트의 시작과 끝
        int start = (i == 0) ? 1 : stations[i - 1] + w + 1;
        int end = (i == stations.size()) ? n : stations[i] - w - 1;
        
        int count = end - start + 1; // 전파가 닿지 않는 아파트의 수
        int wave_len = w * 2 + 1; // 전파 전달 거리
        if(count > 0) answer += count / wave_len + min(count % wave_len, 1);
    }

    return answer;
}