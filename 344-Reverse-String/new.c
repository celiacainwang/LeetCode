void reverseWords(char *s) {
    void _rev(char* s, char* t) {
        --t;
        while (s < t) {
            *s = *s ^ *t;
            *t = *s ^ *t;
            *s = *s ^ *t;;
            ++s;
            --t;
        }
    }

void trim(char* s) {
    int offset = 0;
    char *prev = s, *next = s, *leading = s, *trailing =s ;
    // remove spaces between word.
    do
        while (*next == ' ' && *(next+1) == ' ') next++;
    while (*prev++ = *next++);
    // remove leading spaces
    if ( *leading == ' ') while (*leading++ != '\0') *(leading-1) = *leading; //it will copy the '\0'
    // remove trailing spaces.
    while ( *trailing != '\0') trailing++;
    if (*(trailing-1) == ' ' ) *(trailing-1) = '\0';
}
trim(s);
char* res = s;
char* end = s;
while(*end++ != '\0') {
    if(*end == ' ' || *end == '\0') {
        _rev(s,end);
        s = end+1;
    }
}
_rev(res, end-1);
