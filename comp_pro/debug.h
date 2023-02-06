#ifndef _DEBUG_H_
#define _DEBUG_H_

#ifdef NDEBUG
    // NDEBUGが定義されているときは何もしない
    #define debug2( fmt, ... ) ((void)0)
    #define debug1( ... ) ((void)0)

#else /* !NDEBUG */
    // NDEBUGが定義されていないときはprintfデバッグ用関数化
    #include<stdio.h>
    #include<bits/stdc++.h>
    #define debug2( fmt, ... ) \
        fprintf( stderr, \
                  "[%s] %s:%u # " fmt "\n", \
                  __DATE__, __FILE__, \
                  __LINE__, ##__VA_ARGS__ \
        ) // debug2懇切丁寧にしたもの
    #define debug1(...) fprintf(stderr,__VA_ARGS__) // debug1従来の形
    #define COUT(x) cout<<#x<< " = " <<(x)<< \
    " (L" <<__LINE__<< ")" <<"\n" << flush
#endif /* NDEBUG */
#endif /* _DEBUG_H_ */
