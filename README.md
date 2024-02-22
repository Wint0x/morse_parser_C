# Compiling  
`gcc morse_parser.c -o morse_parser.out`  

## Example Usage  
`
. = dot  
\- =  dash
, = space  

./morse_parser .... . .-.. .-.. --- , .-- --- .-. .-.. -..  
Will display "hello world"  

.morse_parser --show  
Will display a morse code chart!  
`

== [ Morse code table ] ==
[ ] -> ,
[a] -> .-
[b] -> -...
[c] -> -.-.
[d] -> -..
[e] -> .
[f] -> ..-.
[g] -> --.
[h] -> ....
[i] -> ..
[j] -> .---
[k] -> -.-
[l] -> .-..
[m] -> --
[n] -> -.
[o] -> ---
[p] -> .--.
[q] -> --.-
[r] -> .-.
[s] -> ...
[t] -> -
[u] -> ..-
[v] -> ...-
[w] -> .--
[x] -> -..-
[y] -> -.--
[z] -> --..  
[1] -> .----  
[2] -> ..---  
[3] -> ...--   
[4] -> ....-  
[5] -> .....  
[6] -> -....  
[7] -> --...    
[8] -> ---..    
[9] -> ----.    
[0] -> -----    
