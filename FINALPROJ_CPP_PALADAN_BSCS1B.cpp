#include <iostream>// For input/output operations
#include <string>// For using std::string
#include <sstream>// For using stringstream to split text easily
using namespace std;

    void clear(){
    system("clear");// Function to clear the console screen
    }
    
    void magic(){
    while(true){// Main loop to allow counting multiple texts
    clear();// Clear console for a fresh session
    cout << "WELCOME TO WORD+COUNT\n\nPASTE/TYPE YOUR TEXT. Press ENTER twice to finish:\n\n";// Instruction
    
    string text, line, word;// text stores entire input, stores each line, text, period, word temporarily
    int empty = 0, paragraphs = 0, words = 0, sentences = 0, characters = 0; // Counter to track empty lines, paragraphs, words, sentences 
    
    while(true){
    getline(cin, line);// Read one line of input
    if(line == "count" || line.empty()){// it will start counting if user type count in a new line alone 
    //or if the attempts of using empty lines is == to 2
    if(++empty == 2)
    break;// Stop reading after two consecutive empty lines
    }
    else{
    empty = 0;// Reset empty line counter if line has content
    text += line + "\n";//type line to text, keep newline for paragraph detection
    }
    }
    
    // Stringstream reads string like input 
    stringstream gline(text);// Create a stringstream to process text line by line
    while(getline(gline, line)){ 
    // Check if line has at least one character that is not a space or tab
    if(line.find_first_not_of(" \t") != string::npos/*meaning not found, pero dahil may ! the value is Reversed*/) 
    paragraphs++;// Increment paragraph count
    }
    
    bool gPnct = false;// this has a value of false if Hindi Tayo ginamit ng punctuation marks 
    for(char c : text){
    //this checks if merong( . ! ? ) sa loob ng text
    if(c == '.' || c == '!' || c == '?'){
    if(!gPnct){// checks if Hindi Tayo ginamit ng punctuation marks
    sentences++;// if gumamit Tayo then add value to sentence 
    gPnct = true;// sets the value to true para Hindi na mag bilang ulit
    }
    }
    else{ // else Hindi Tayo gumamit ng punctuation marks so nothing 
    gPnct = false; 
    }
    }
    for(char c : text){// loop inside the text to count all 
    characters++;//add value to characters 
    }
    
    for(char &c : text){// Loop through each character in the text
    // Replace any common punctuation with space para ma bilang ng Tama Yung words
    if(c==','|| c == '\÷'|| c == '!' || c == '.' ||
    c == '?' || c == ';' || c == ':' || c == '"' || 
    c == '*' || c == '+' || c == '/' || c == '\\'||
    c == '@' || c == '#' || c == '&' || c == '(' ||
    c == ')' || c == '{' || c == '}' || c == '<' ||
    c == '>' || c == '$' || c == '1' || c == '2' ||
    c == '3' || c == '4' || c == '5' || c == '6' ||
    c == '7' || c == '8' || c == '9' || c == '`' ||
    c == '[' || c == ']' || c == '=' || c == '^' ||
    c == '~' || c == '$' || c == '%' || c == '-' ||
    c == '0') c = ' ';// Replace punctuation with a space
    }
    // stringstream automatically separates words using spaces, tabs, newlines
    stringstream rwrds(text);// this extract the words inside of the text to rwrds, para lng syang cout << text pero to rwrds
    //stringstream reads from string instead of user input 
    while(rwrds >> word) // Extract words one by one 
    words++;
    
    cout<<"\nTotal Words: "<< words;// Print total words
    cout<<"\nTotal Sentences: "<< sentences;// print total sentence 
    cout<<"\nTotal Paragraphs: "<< paragraphs;// Print total paragraphs
    cout<<"\nTotal Characters: ";
    if(text.empty()){
    cout<<characters;
    }
    else{cout<< characters-1;}
    cout << "\nCount another text? (y/n): ";
    char choice;
    cin >> choice;// Read user's choice
    cin.ignore();// Clear the newline character left in the input buffer
    if(choice != 'y' && choice != 'Y')
    break; // Exit loop if user chooses anything other than Y/y
    }
    clear();// Clear screen one last time before exiting
    cout << "\nBye Love!\n";
    }
int main(){
    magic();
    return 0; // End program
}
/*Penatration Test/Accuracy test:

Hello world! This is a test: does it count correctly? Numbers like 123 should be ignored, but words count. Newlines
should start new paragraphs. Multiple spaces   here shouldn’t break anything. Tabs\talso shouldn’t add extra paragraphs. Punctuation! Does it work? Yes. Quotation marks “like this” too. Hyphens - should be safe. Symbols @#$%^&*() are ignored. Sentences end with periods. Exclamation! Or question? Even ellipses… work. Words with apostrophes like don’t or it’s count. Now we add a new paragraph here. Another line starts. And one more. Testing, testing, 1, 2, 3. End of test.

results should be;
88 words
22 sentences
2 paragraphs 
604 characters 
*/