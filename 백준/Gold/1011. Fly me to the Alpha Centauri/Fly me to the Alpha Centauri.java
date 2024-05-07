import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int t = Integer.parseInt(br.readLine());
        for(int i = 0; i < t; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            
            int dist = y - x;
            
            int answer = 0;
            for(int move = 1; dist > 0; move++){ // move = 현재 작동에서의 이동 거리
                if(dist >= move){
                    answer++;
                    dist -= move;
                }
                if(dist >= move){
                    answer++;
                    dist -= move;
                }
                
                if(0 < dist && dist <= move){
                    answer++;
                    break;
                }
            }
            
            bw.write(String.valueOf(answer) + "\n");
        }
        
        bw.flush();
        
        br.close();
        bw.close();
    }
}