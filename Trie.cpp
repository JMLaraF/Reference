class Node{
  	public:
		bool isWord;
		map <char, Node*> letters;
};

class Trie{
	private:
		Node* root;
	
	public:
		Trie(){
			root = new Node();
		}
		void InsertWord(string& word){
			Node* current = root;
			for(int i = 0; i < word.size(); i++){
				
				if(current -> letters.find(word[i]) == current -> letters.end()){
					current -> letters[word[i]] = new Node();
				}
				current = current -> letters[word[i]];
			}
			current -> isWord = true;
		}
	
		bool FindWord(string& word){
			Node* current = root;
			for(int i = 0; i < word.size(); i++){
				if(current -> letters.find(word[i]) == current -> letters.end())
					return false;
				current = current -> letters[word[i]];
			}
			return current -> isWord;
		}	
};