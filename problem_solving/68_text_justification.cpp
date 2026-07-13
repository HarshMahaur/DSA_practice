#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {

public:

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> answer;
        int l=0;
        while(l<words.size()){
            vector<int> single_string;
            single_string.push_back(-1);
            int no_of_char(words[l].size());
            int last =l;
            // construct the bassic structure of the max width sentence
            for(int i =l+1;i<words.size();i++){
                //     no_of_char+= words[i].size()+1;
                //     single_string.push_back(1);
                //     single_string.push_back(-1);
                // if(no_of_char>maxWidth){
                //     no_of_char-=(words[i].size()+1);
                //     single_string.pop_back();
                //     single_string.pop_back();
                //     last = i-1;
                    
                //     break;

                // }
                if(no_of_char + 1 + words[i].size() > maxWidth)
                    break;

                no_of_char += words[i].size() + 1;

                single_string.push_back(1);
                single_string.push_back(-1);

                last = i;   // add this
                
            }
            // distributing extra space
            int no_of_extra_space=maxWidth-no_of_char;
            for(int i=1;i<single_string.size();i=i+2){
                if(no_of_extra_space==0){
                    break;
                }
                single_string[i]++;
                no_of_extra_space--;
                if(i+2>=single_string.size()){
                    i=-1;
                }

            }
            // constructing the actual string;
            string sentence;
            int j=l;
            for(int i=0;i<single_string.size();i++){
                if(single_string[i]==-1){
                    sentence += words[j];
                    j++;
                }
                else{
                    for(int k=0;k<single_string[i];k++){
                        sentence+= ' ';
                    }
                }

            }
            while(sentence.size() < maxWidth){
                sentence += ' ';
            }
            answer.push_back(sentence);
            l=last+1;
        }
        string text = answer[answer.size()-1];
        answer.pop_back();

        stringstream ss(text);
        string word;
        string cleanedText = "";
        
        // Extract words automatically ignoring extra middle spaces
        while (ss >> word) {
            if (!cleanedText.empty()) {
                cleanedText += " ";
            }
            cleanedText += word;
        }
        
        // Calculate the difference in length and append the missing spaces
        if (text.length() > cleanedText.length()) {
            cleanedText.append(text.length() - cleanedText.length(), ' ');
        }
        answer.push_back(cleanedText);


        return answer;
    }
};

int main() {

    vector<string> words = {
        "This", "is", "an", "example", "of", "text", "justification."
    };

    int maxWidth = 16;
    Solution obj;
    vector<string> result = obj.fullJustify(words, maxWidth);

    cout << "Output:\n\n";
    for (const auto &line : result) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}