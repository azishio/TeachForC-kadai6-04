// 迷えるC科のみんなへ

/*================================================================
kadai6-04 作成例

いくつかの処理方法の例を上げるので参考まで。
コメント中で、変数、配列、定数名は'x'と書く。本作例固有の数字は"0"と記す。
そのプログラムに関する記述は直下の行で行う。
ただし大まかな流れは／*xxx*／でプログラム群の先頭に示す。

#用語の定義 //不正確かもしれんけど許してね。

- 宣言: 変数/配列を新しく作成すること
- 初期化: 変数/配列の宣言時に値を代入すること。もしくは変数/配列に初めて値を代入すること
- 代入: 変数/配列に値を格納すること
- 参照: 配列/変数の要素を取り出すこと
- 出力: 黒い画面に文字として情報を表示させること
- 引数: 関数（printfとか、c言語にもともと備わっている命令）のカッコ内に入力する値
        printf("レポート終わらねぇ。%d,%c\n", number, charactor)の場合、
       「"レポート終わらねぇ。%d,%c\n"」が第一引数、「number」が第二引数、「charactor」が第三引数
- フォーマット指定子（変換指定子）:%dとか%cとか。書式を指定する特別な文字列

#本作例での宣言ルール

- １つ目の行列は配列'A'で定義する
- １つ目の行列の大きさは'L'行'M'列

- ２つ目の行列は配列'B'で定義する
- 2爪の行列の大きさは'M'行'N'列

- 答えを格納する配列を'C'とする
- 答えの行列の大きさは'L'行'M'列である

- 答えを格納する変数を'c'とする
- 上の配列'C'を使う場合には使用しない（おまけで使うよ）

- 変数および配列は可読性のため、それを使用するプログラムの直前に宣言する
- それを使用するプログラムより前であれば、どこで宣言しても構わない（for/if文の{}の中とかはやめてね）

以下の内容の正確性については保証しない。私の認識が間違ってるかもしれないしね
================================================================*/

#include <stdio.h>
// ヘッダファイルのインクルード。おまじないとでも思っておいて

#define L 3
#define M 4
#define N 5
// 行列の大きさの定義。指導書に合わせてマクロ定義する

int main(void) {
    printf("1つ目の行列（%d行%d列）を入力\n１行はコンマ区切りで\n", L, M);
    // ユーザーに入力する行列の大きさや入力方法を伝える

    int A[L][M];
    // 'A'という名前の'L'行'M'列の二次元配列を宣言する。

    /* 配列への入力 */  //--------------------------------------------------------
    // #define INPUTの値を1から3までに変えることで、実行したときに動く処理を変えることができる
    // どの書き方でも動くことを確認してみてね！！

#define INPUT 1  // ここの値を変えると処理方法が変えられるよ！（半角で1から3）

//================================================================
#if INPUT == 1
    // 1行ずつscanfを実行
    //================================================================

    scanf("%d,%d,%d,%d", &A[0][0], &A[0][1], &A[0][2], &A[0][3]);
    // 'A'の１行目（c言語では0から数え始めることに注意）の各列に値を代入
    // scanfの第一引数の「" "」内に複数のフォーマット指定子が存在した場合、第二引数以降に指定した変数/配列にその順番で格納される
    // その際、フォーマット指定子の間に何らかの文字が存在した場合、それらは読み捨てられる
    // 例えば、scanf("%d-%d", &a, &b); として、「123-456」と入力した場合、変数aに123、変数bに456が代入される
    scanf("%d,%d,%d,%d", &A[1][0], &A[1][1], &A[1][2], &A[2][3]);
    // 「&」について、詳しくは範囲外なので省略。変数/配列がchar型以外であれば必要。
    scanf("%d,%d,%d,%d", &A[2][0], &A[2][1], &A[2][2], &A[2][3]);

//================================================================
#endif
#if INPUT == 2
    // ループでscanfを実行
    //================================================================

    for (int i = 0; i < L; i++) {
        // 'A'の行数だけループ

        scanf("%d,%d,%d,%d", &A[i][0], &A[i][1], &A[i][2], &A[i][3]);
        // for文のカウンタ変数を用いて'A'の行を指定している
        // for文についてのちょっと詳しい説明は以下
    }

    // for文には、3つの式（プログラム）を渡す。
    // １つ目は、for文が開始する１回目だけに実行されるプログラムである。
    // 普通はカウンタ変数と呼ばれる、{}の中のプログラムが何回実行されたかを管理する変数を宣言する。
    // for文の外で使用する予定がない限りカウンタ変数は初期化ではなく宣言をしたほうが良い。
    // つまり、「for(i = 0; ...)」よりも「for(int i = 0; ...)」の方が良い。
    // for文の第一引数でカウンタ変数を宣言すると、{}の外からカウンタ変数を参照できなくなる。
    // そのため、カウンタ変数を使い回すことによる意図しない動作（プログラマのミスによる）を回避することが期待できる。

    // ２つ目は、{}プログラムが実行される前に毎回読まれる式である。
    // その式が返す値が1（＝その条件式が満たされている）の場合はfor文の中のプログラムを実行し、0（＝条件式が満たされていない）の場合はループを抜ける。

    // 3つ目は{}中のプログラムがすべて実行し終わった際に毎回実行されるプログラムである。
    // 通常はカウンタ変数の更新に使用し、カウンタ変数に値を足したり引いたりする。（かけたり割ったりもできるけど、多分使わない）
    // for分の第３引数で、インクリメント/デクリメント演算子を使う場合、前置/後置は区別されない。（「i++」とか「++i」とか「i--」とか「--i」とか）

//================================================================
#endif
#if INPUT == 3
    // ループで行列の各要素を取得
    //================================================================
    //ちょっと難しいかもしれないのでカウンタ変数について詳しめに書いてみた

    for (int i = 0; i < L; i++) {
        //カウンタ変数'i'は行数を管理する
        //'i'は"0"、"1"、"2"の値を取る(0 <= i <= L)

        for (int j = 0; j < M; j++) {
            //カウンタ変数'j'は列数を管理する
            //'j'は"0"、"1"、"2"、"4"の値を取る(0 <= j <= M)

            sscanf("%d", &A[i][j]);
            // 入力された整数を'A'のi行j列目に代入する
        }
        // jが"5"になった時点で、{}内のプログラムが実行されずにループを抜ける（'A'に"5"列目は存在しない）
    }
// iが"4"になった時点で、{}内のプログラムが実行されずにループを抜ける（'A'に"4"行目は存在しない）

//================================================================
#endif  //気にしないでね!!

    //****************************************************************
    //同様にして'B'も取得している
    //次の「//** ...」まで読み飛ばして良い
    printf("2つ目の行列（%d行%d列）を入力\n１行はコンマ区切りで\n", M, N);
    int B[M][N];
#if INPUT == 1 || INPUT == 2
    for (int i = 0; i < M; i++) {
        scanf("%d,%d,%d,%d,%d", &B[i][0], &B[i][1], &B[i][2], &B[i][3], &B[i][4]);
    }
#endif
#if INPUT == 3
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &B[i][j]);
        }
    }
#endif
    //****************************************************************

    /* 行列の積の計算 */  //--------------------------------------------------------

    int C[L][N] = {0};
    //答えを格納する'L'行'N'列の二次元配列

    //配列の宣言時、0で初期化する際は以下のようにする
    // int array[3] = {0, 0, 0};
    //これを略記すると、
    // int array[3] = {0};
    //とできる。これは、初期化時に要素を省略した場合、以降は「0」で初期化されるという仕様のためである。

    //※初期化時に要素を省略しない場合、「int array[] = {0, 0, 0};」というように要素数を省略できる。
    //  ただし、多次元配列の場合、一番右側の要素数は省略することができない。
    //  例）int array[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    //  これは、
    //  int array[][5] = {{1, 2, 3}, {4, 5, 6}};
    //  と宣言した場合、上述の略記に従って以下のような配列が作られるためである（たぶん）
    //  宣言されたarrayの要素： {{1, 2, 3, 0, 0}, {4, 5, 6, 0, 0}}

    for (int i = 0; i < L; i++) {
        //'C'の行数分だけループ
        for (int j = 0; j < N; j++) {
            //'C'の列数分だけループ
            for (int k = 0; k < M; k++) {
                //'A'の列数or'B'の行数分だけループ（行列の積の定義による）

                C[i][j] += A[i][k] * B[k][j];
                // Cに'A'の要素と'B'の要素の掛け算を加算する
                //本ファイルの最後に貼ったリンクの画像（以降、画像と言ったらコレのこと）を見るとわかりやすいかも
            }
            //ループが進むごとに、画像の文字を使って以下に示すような処理が実行される（i,jは0かつ、c_11の初期値は0とする）
            // k = 0: c_11 += a_11 * b_11
            // k = 1: c_11 += a_12 * b_21
            //...
        }
        //ループが１回終わるたびに1つの要素の計算が終わる。画像でいうと以下のように表せる（iは0であるとする）
        // j = 0: c_11 計算完了
        // j = 1: c_12 計算完了
        // j = 2: c_13 計算完了
        //...
    }
    //ループが１回終わるたびに１行の計算が終わる。画像でいうと以下のように表せる（iは0であるとする）
    // i = 0: c_1行目 計算完了
    // i = 1: c_2行目 計算完了
    // i = 2: c_3行目 計算完了
    //...

    /* 計算した行列の出力 */  //--------------------------------------------------------
    for (int i = 0; i < L; i++) {
        //'C'の行数分ループ
        for (int j = 0; j < N; j++) {
            //'C'の列数分ループ

            printf("%d\t", C[i][j]);
            //'i'行'j'列目の'C'の要素を出力する
            //各列はタブで区切っている
            //（これだと各要素の値の桁数が大きく違う場合、列がずれる。もっと綺麗に出力したい人はおまけを見てね）
        }

        printf("\n");
        // 1行分の出力が終わったら改行する
    }
}

//行列の積 参考画像//
// https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fw3e.kanazawa-it.ac.jp%2Fmath%2Fcategory%2Fgyouretu%2Fimage%2Fgyouretu1.gif&f=1&nofb=1
