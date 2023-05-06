import java.util.*;

class Pair{
    Integer idx, play;
    Pair(int idx, int play){
        this.idx = idx;
        this.play = play;
    }
}

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        
        int n = genres.length;
        
        Map<String, Integer> genresCnt = new HashMap<>();
        Map<String, List<Pair>> genresList = new HashMap<>();
        
        for(int i = 0; i < n; i++){
            String gen = genres[i];
            int play = plays[i];
            
            // 장르 카운트 세기
            if(genresCnt.containsKey(gen)){
                genresCnt.put(gen, genresCnt.get(gen) + play);
            }else genresCnt.put(gen ,play);
            
            // 장르 리스트 생성
            if(genresList.containsKey(gen)){
                genresList.get(gen).add(new Pair(i, play));
            }else {
                genresList.put(gen, new ArrayList(List.of(new Pair(i,play))));
            }
        }
        
        List<Map.Entry<String, Integer>> sortedGenresCnt = new ArrayList<>(genresCnt.entrySet());
        
        sortedGenresCnt.sort((e1, e2) -> e2.getValue().compareTo(e1.getValue()));
        
        List<Integer> ansList = new ArrayList<>();
        
        for(Map.Entry<String, Integer> genreEntry: sortedGenresCnt){
            String gen = genreEntry.getKey();
            List<Pair> genList = genresList.get(gen);
            
            genList.sort((gen1, gen2) -> {
                if(gen1.play == gen2.play) return gen1.idx.compareTo(gen2.idx);
                else return gen2.play.compareTo(gen1.play);
            });
            
            int cnt = 0;
            
            for(Pair tPair: genList){
                if(cnt == 2) break;
                ansList.add(tPair.idx);
                cnt++;
            }
        }

        int[] ans = new int[ansList.size()];
        
        for(int i = 0; i< ans.length; i++) ans[i] = ansList.get(i);
        
        return ans;
    }
}