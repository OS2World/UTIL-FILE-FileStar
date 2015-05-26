 /*  ________________________________________                             */
 /*  ★FileStar★  File List Utility for OS/2                             */
 /*  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                             */
 /*  Version 2.33                          CopyRight Ｇeorge(島田高広)    */
 /*                                        KGG02311@niftyserve.or.jp      */
 /* ●著作権                               1996.09.30                     */
 /*                                                                       */
 /*   －ＦｉｌｅＳｔａｒはフリーウエアとして，ソースコードを含めて公開    */
 /*　 　します．再配布・再利用は自由に行って結構です．                    */
 /*                                                                       */
 /* 　－ただし，作品としての「ＦｉｌｅＳｔａｒ」の著作件はＧeorge(島田    */
 /*     高広)が保持します．当「ＦｉｌｅＳｔａｒ」の改修公開はＧeorge      */
 /*     (島田高広)によってのみ有効であり，ソースコードを再利用すること    */
 /*     は認めますが，それを「ＦｉｌｅＳｔａｒ」の別バーションとして      */
 /*     Ｇeorge(島田高広)の許可なく公開することを禁止致します．           */
 /*                                                                       */
 /*　●免責事項                                                           */
 /*                                                                       */
 /* 　－当「ＦｉｌｅＳｔａｒ」の一切の利用は，使用者の責任において行う    */
 /* 　　ものとし，この使用により直接的間接的に生じたいかなる損害につい    */
 /* 　　ても，作者であるＧeorge(島田高広)は一切責任を負いません．         */
 /*                                                                       */
 /*  ●変更履歴                                                           */
 /*     1994.11.18  Version0.80にて初公開(lib1.fos2@niftyserve)           */
 /*     1994.11.27  Version1.00                                           */
 /*                   -終了動作の改善                                     */
 /*                   -ﾃﾞｨﾚｸﾄﾘｰ･ｺﾋﾟｰ時のｺﾋﾟｰ先指定が'\'で終わるとｴﾗ-に    */
 /*                    なるﾊﾞｸﾞを修正                                     */
 /*                   -..のｺﾋﾟｰは無視する                                 */
 /*                   -ｺﾋﾟｰ(ｷｰC)時のﾒｯｾｰｼﾞを改訂                          */
 /*                   -ｺﾋﾟｰ終了時のｳｲﾝﾄﾞｳを自動ｸﾛｰｽﾞしないように変更      */
 /*                   -ﾌｧｲﾙ･ﾏｽｸ文字指定機能追加(ｷｰY)                      */
 /*                   -ﾌｧｲﾙ削除機能の追加(ｷｰD)                            */
 /*                   -ﾃﾞｨﾚｸﾄﾘｰ作成機能の追加(ｷｰK)                        */
 /*                   -1文字ﾃﾞｨﾚｸﾄﾘｰから親ﾃﾞｨﾚｸﾄﾘｰへ行った場合のｶｰｿﾙ位置  */
 /*                    がおかしくなるﾊﾞｸﾞを修正                           */
 /*                   -ﾄﾞﾗｲﾌﾞの準備が出来ていない後の誤動作ﾊﾞｸﾞを修正     */
 /*                    (PathLenに0が返り戻さなかったためDir名が認識不可)  */
 /*                   -画面桁数に応じﾀｲﾄﾙ表示を変更                       */
 /*                   -ﾃﾞｨﾚｸﾄﾘｰでのｷｰE(編集)を無視する                    */
 /*                   -ﾌｧｲﾙ移動機能の追加(ｷｰM)                            */
 /*                   -ﾌｧｲﾙ改名機能の追加(ｷｰN)                            */
 /*                   -ﾄﾞﾗｲﾌﾞ未接続のﾒｯｾｰｼﾞ色を通常の黄色に変更           */
 /*                   -文字入力時以外はｶｰｿﾙを不可視にする                 */
 /*     1994.12.25  Version1.50                                           */
 /*                   -ﾌｧｲﾙ名ｿｰﾄ機能の追加(ｷｰS)                           */
 /*                   -ﾌﾟﾛｸﾞﾗﾑ変数名の短縮/整理(表示情報の構造体化等)     */
 /*                   -先頭ﾌｧｲﾙへの移動(Homeｷｰ)を追加                     */
 /*                   -最終ﾌｧｲﾙへの移動(Endｷｰ)を追加                      */
 /*                   -ﾌｧｲﾙ名頭出し機能(Deleteｷｰ)を追加                   */
 /*                   -初期設定ﾌｧｲﾙのｻﾎﾟｰﾄを開始(FILESTAR.INI)            */
 /*                   -INIﾌｧｲﾙでEditor名/ｾｯｼｮﾝの別･同一指定を追加         */
 /*                   -編集(ｷｰE)でﾌｧｲﾙ名を変更可能とする                  */
 /*                   -またﾃﾞｨﾚｸﾄﾘｰでのｷｰE(編集)無視を解除                */
 /*                   -ｳｲﾝﾄﾞｳ･ｻｲｽﾞ変更機能の追加(ｷｰW)                     */
 /*                   -改名(ｷｰN)のﾒｯｾｰｼﾞを改訂                            */
 /*                   -ﾄﾞﾗｲﾌﾞ変更/ﾌｧｲﾙ削除/FileStar終了のﾒｯｾｰｼﾞ変更       */
 /*                   -ｺﾏﾝﾄﾞ実行機能の追加(ｷｰX)                           */
 /*                   -F3/ｷｰQで終了を追加                                 */
 /*                   -INIﾌｧｲﾙで"常にｿｰﾄ"を追加                           */
 /*                   -INIﾌｧｲﾙでｺﾏﾝﾄﾞ/ﾌﾟﾛｸﾞﾗﾑ実行のｾｯｼｮﾝ/自動ｸﾛｰｽﾞ指定    */
 /*                   -F2で設定変更を追加                                 */
 /*                   -INIﾌｧｲﾙで起動時表示ﾃﾞｨﾚｸﾄﾘｰを追加                  */
 /*                   -INIﾌｧｲﾙでﾌｧｲﾙ名拡張子とﾌﾟﾛｸﾞﾗﾑの関連付けを追加     */
 /*                   -ﾀｲﾄﾙ･ﾛｺﾞ画面を追加                                 */
 /*                   -ﾌｧｲﾙ削除のﾒｯｾｰｼﾞを変更                             */
 /*                   -INIﾌｧｲﾙでﾀｲﾄﾙ･ﾛｺﾞ画面表示時間設定を追加            */
 /*     1995. 1.29  Version2.00                                           */
 /*                   -INIﾌｧｲﾙで起動時ｳｲﾝﾄﾞｳ･ｻｲｽﾞ指定を追加               */
 /*                   -ﾌﾟﾛｸﾞﾗﾑ起動中にﾘﾑｰﾊﾞﾌﾞﾙ･ﾃﾞｨｽｸが変えられた際,ﾌｧｲﾙ   */
 /*                    一覧表示がおかしくなるﾊﾞｸﾞを修正                   */
 /*                   -ﾃﾞｨｸｽ･ｻｲｽﾞ(ﾌﾘｰ/ﾄｰﾀﾙ)表示を追加                     */
 /*                   -ﾌｧｲﾙ属性変更(ｷｰA)を追加                            */
 /*                   -INIﾌｧｲﾙで"自動ｸﾛｰｽﾞなしの無視"を追加               */
 /*                   -ｺﾏﾝﾄﾞ実行(ｷｰX)で別ｾｯｼｮﾝの時,入力ｺﾏﾝﾄﾞが反映しない  */
 /*                    ﾊﾞｸﾞを修正.                                        */
 /*                   -ﾌｧｲﾙ削除(ｷｰD)でReadOnly等のﾌｧｲﾙ削除も可能にする.   */
 /*                   -ﾌｧｲﾙ削除(ｷｰD)でﾃﾞｨﾚｸﾄﾘｰ一括削除も可能にする.       */
 /*                   -PF12でTheater表示を追加                            */
 /*                   -SPACEｷｰによるﾌｧｲﾙのﾏｰｸを追加                       */
 /*                   -現行ﾃﾞｨﾚｸﾄﾘｰ･ｻｲｽﾞの表示を追加                      */
 /*                   -Insertｷｰによる全ﾌｧｲﾙ･ﾏｰｸを追加                     */
 /*                   -ﾈｽﾄされたﾃﾞｨﾚｸﾄﾘｰの作成を可能にする                */
 /*                   -XCOPY呼び出しをOｷｰに移動                           */
 /*                   -CｷｰをDosCopy関数によるﾌｧｲﾙのｺﾋﾟｰとして構成         */
 /*                   -ﾃﾞｨﾚｸﾄﾘｰ入力で入力が空はｴﾗｰとする                  */
 /*                   -ﾃﾞｨﾚｸﾄﾘｰ作成で絶対ﾊﾟｽ/相対ﾊﾟｽとも対応可能に改善    */
 /*                   -ﾏｰｸﾌｧｲﾙ/ﾃﾞｨﾚｸﾄﾘｰのｺﾋﾟｰ機能を追加(ｷｰC)              */
 /*                   -ﾏｰｸﾌｧｲﾙ/ﾃﾞｨﾚｸﾄﾘｰの削除機能を追加(ｷｰD)              */
 /*                   -ﾏｰｸﾌｧｲﾙの属性変更を追加(ｷｰA)                       */
 /*                   -ﾌｧｲﾙ移動機能(ｷｰM)をｺﾋﾟｰ機能と削除機能により再構成  */
 /*                     他ﾄﾞﾗｲﾌﾞへの移動やﾃﾞｨﾚｸﾄﾘｰの移動を可能にする      */
 /*                   -ﾏｰｸﾌｧｲﾙ/ﾃﾞｨﾚｸﾄﾘｰの移動機能を追加(ｷｰM)              */
 /*     1995. 2. 6  Version2.01                                           */
 /*                   -ﾌｧｲﾙ削除後にﾌｧｲﾙが0件になった場合に異常終了が発生  */
 /*                    するﾊﾞｸﾞを修正                                     */
 /*                   -ﾌｧｲﾙ表示機能を追加(V/Enterｷｰ)                      */
 /*                   -ｶｰｿﾙ行が..の上の時Mｷｰでﾏｰｸﾌｧｲﾙが無視されるﾊﾞｸを修正*/
 /*                   -Remane等の後にPageNo計算がおかしくなりPageUpできな */
 /*                    くなるﾊﾞｸを修正                                    */
 /*                   -ｺﾋﾟｰ先空き容量不足のｴﾗｰﾒｯｾｰｼﾞを追加                */
 /*                   -BackSpaceで親ﾃﾞｨﾚｸﾄﾘｰへの移動を追加                */
 /*                   -\ｷｰでﾙｰﾄ･ﾃﾞｨﾚｸﾄﾘｰへの移動を追加                    */
 /*                   -ﾄﾞﾗｲﾌﾞ/ﾃﾞｨﾚｸﾄﾘｰ名の表示を変更                      */
 /*                   -Copy/削除時のｴﾗｰ･ﾒｯｾｰｼﾞを改善                      */
 /*                   -終了ﾒｯｾｰｼﾞでEnterで終了できるようにする            */
 /*                   -ｷｰ1-0でﾄﾞﾗｲﾌﾞA-Jへ移る機能を追加                   */
 /*                   -説明(PF1),設定(PF2)をEnterｷｰでも終了可能とする     */
 /*     1995. 4. 2  Version2.15                                           */
 /*                   -Move機能で宛先ﾄﾞﾗｲﾌﾞが一杯の際のﾒｯｾｰｼﾞ処理の改善   */
 /*                   -RC108へのｴﾗｰ･ﾒｯｾｰｼﾞ(ﾄﾞﾗｲﾌﾞがﾛｯｸされている)追加     */
 /*                   -Yｷｰ(ﾏｽｸ文字)処理後にﾌｧｲﾙ一覧表示がおかしくなるﾊﾞｸﾞ */
 /*                    を修正                                             */
 /*                   -ﾏｽｸ文字の表示を追加                                */
 /*                   -文字入力ｳｲﾝﾄﾞｳで左右ｶｰｿﾙ移動/Deleteｷｰの使用可にする*/
 /*                   -ｳｲﾝﾄﾞｳの横ｻｲｽﾞを大きくした場合にｺﾞﾐが出るﾊﾞｸﾞを修正*/
 /*                   -同一ﾃﾞｨﾚｸﾄﾘｰ自身へのｺﾋﾟｰ/移動のｴﾗｰ･ﾒｯｾｰｼﾞ追加      */
 /*                   -ｺﾋﾟｰ/移動の宛先ﾃﾞｨﾚｸﾄﾘｰ名に,前回指定の名前の一部が */
 /*                    付加されてしまうﾊﾞｸﾞを修正                         */
 /*                   -Move機能で宛先入力ｴﾗｰを起こすと,その後ﾃﾞｨﾚｸﾄﾘｰの   */
 /*                    ｺﾋﾟｰが正常に行われず,Moveではﾌｧｲﾙの消失等を起こす  */
 /*                    ﾊﾞｸﾞを修正                                         */
 /*                   -複数ﾌｧｲﾙ/ﾃﾞｨﾚｸﾄﾘｰをｻﾌﾞﾃﾞｨﾚｸﾄﾘｰを新たに造りCopy/Move*/
 /*                    する際,ﾃﾞｨﾚｸﾄﾘｰのﾌｧｲﾙが増えたことに対応せず間違った*/
 /*                    ﾌｧｲﾙのCopy/Moveを行ってしまうﾊﾞｸﾞを修正            */
 /*                   -ﾌｧｲﾙ･ｺﾋﾟｰの"現在存在するﾃﾞｨﾚｸﾄﾘｰではありません"ﾒｯｾｰ*/
 /*                    ｼﾞで処理を取り消す(N/Esc)とRC0002のｴﾗｰ･ﾒｯｾｰｼﾞが表示*/
 /*                    されるﾊﾞｸﾞを修正                                   */
 /*                   -Y:yes/N:no選択を全てY:yes(Enter)/N:no(Esc)にする   */
 /*                   -.batﾌｧｲﾙのEnterｷｰでの動作を表示にする　            */
 /*                   -ﾄﾞﾗｲﾌﾞ･ﾗﾍﾞﾙの表示を追加                            */
 /*     1995. 5.30  Version2.20                                           */
 /*                   -ﾌｧｲﾙの表示の後等で画面全体の再表示を行った場合に,  */
 /*                    ﾄﾞﾗｲﾌﾞ･ﾗﾍﾞﾙの文字数が正しくなくなるﾊﾞｸﾞを修正      */
 /*                   -FileStarの終了のﾒｯｾｰｼﾞが切れているﾊﾞｸﾞを修正       */
 /*                   -INIﾌｧｲﾙの<Extension>で,ﾌﾟﾛｸﾞﾗﾑへのﾊﾟﾗﾒｰﾀ指定をｻﾎﾟｰﾄ*/
 /*                    (&Fが選択ﾌｧｲﾙ名)                                   */
 /*                   -ﾌｧｲﾙの検索機能の追加(Fｷｰ)                          */
 /*                   -"同一ﾃﾞｨﾚｸﾄﾘｰへのｺﾋﾟｰ/削除は.."を"../移動は"に訂正 */
 /*                   -RC0023(ﾃﾞｰﾀCRCｴﾗｰ)のﾒｯｾｰｼﾞを追加                   */
 /*                   -文字入力ｳｲﾝﾄﾞｳの操作の改善(細かいﾊﾞｸﾞの修正)       */
 /*                   -Iｷｰでｼｬﾄﾞｰ･ｱｲｺﾝを登録する機能を追加                */
 /*                    (ﾌﾟﾛｸﾞﾗﾑ/INFﾌｧｲﾙ以外の場合)                        */
 /*                   -ﾏｰｸﾌｧｲﾙの連続実行機能を追加                        */
 /*                    (拡張子関連付けﾌﾟﾛｸﾞﾗﾑのみ)                        */
 /*     1996.01.16  Version2.30                                           */
 /*                   -RC0206(名前が長過ぎ)のﾒｯｾｰｼﾞを追加                 */
 /*                   -RC0021(ﾄﾞﾗｲﾌﾞ未装着)のﾒｯｾｰｼﾞを追加                 */
 /*                   -ﾏｸﾛ機能の追加(Shift+ｱﾙﾌｧﾍﾞｯﾄ･ｷｰ/PF4)               */
 /*                   -ﾏｰｸﾌｧｲﾙの連続ｱｲｺﾝ登録機能を追加(Iｷｰ)               */
 /*                   -ﾃﾞｨﾚｸﾄﾘｰ削除時に内部のReadOnlyﾌｧｲﾙの属性ﾘｾｯﾄを     */
 /*                     system関数(ｺﾏﾝﾄﾞ呼び出し)で行っていたのを         */
 /*                     DosSetPathInfo関数に変更し,速度を向上.            */
 /*                   -Move機能で同一ﾄﾞﾗｲﾌﾞ内の場合は,Copy/削除でなく     */
 /*                     DosMove関数によるﾃﾞｨﾚｸﾄﾘｰ情報のみで行うようにし,  */
 /*                     不要なｺﾋﾟｰ動作を無くし速度を向上.                 */
 /*                   -RC0027(ｾｸﾀｰが見つからない)のﾒｯｾｰｼﾞを追加           */
 /*                     (音楽CDへｺﾋﾟｰしようとした場合など)                */
 /*                   -Yｷｰ(ﾜｲﾙﾄﾞ･ｶｰﾄﾞ)指定の際に以前入力の文字が付いてしま*/
 /*                     うﾊﾞｸﾞを修正                                      */
 /*                   -ﾃﾞｨﾚｸﾄﾘｰのｺﾋﾟｰ/移動で宛先に同一名ﾌｧｲﾙがある時に    */
 /*                     ﾃﾞｨﾚｸﾄﾘｰ内ﾌｧｲﾙでその同一名ﾌｧｲﾙを上書きするﾊﾞｸﾞを  */
 /*                     修正                                              */
 /*                   -関連付けﾌﾟﾛｸﾞﾗﾑ実行表示のｳｲﾝﾄﾞｳを変更              */
 /*                   -ｺﾋﾟｰ/移動先に無効なﾃﾞｨﾚｸﾄﾘｰ名(ex.\\\\)を指定した時 */
 /*                     何もﾒｯｾｰｼﾞを出さないことがあるﾊﾞｸﾞを修正          */
 /*                   -.comのﾌﾟﾛｸﾞﾗﾑを実行する際,ｳｲﾝﾄﾞｳの自動ｸﾛｰｽﾞが指定さ*/
 /*                     れているのに"指定されていません"のﾒｯｾｰｼﾞが出るﾊﾞｸﾞ*/
 /*                     を修正                                            */
 /*                   -ﾏｰｸﾌｧｲﾙ削除/移動の内部ﾛｼﾞｯｸの改善                  */
 /*                   -ﾄﾞﾗｲﾌﾞ未ﾌｫｰﾏｯﾄの場合(RC0026)のﾒｯｾｰｼﾞを追加         */
 /*                   -文字入力時のDeleteｷｰが異常な動作をするﾊﾞｸﾞを修正   */
 /*                   -ﾌｧｲﾙ検索で見つからない時に表示ﾃﾞｨﾚｸﾄﾘｰがﾙｰﾄになるﾊﾞ*/
 /*                     ｸﾞを修正                                          */
 /*                   -親ﾃﾞｨﾚｸﾄﾘｰ(..)でのﾌｧｲﾙ編集の時,ﾌｧｲﾙ名指定ﾎﾞｯｸｽは   */
 /*                     ｸﾞﾗﾝｸにする                                       */
 /*                   -ｼﾞｬﾝﾌﾟ機能の追加(Jｷｰ)                              */
 /*                   -ﾋｽﾄﾘｰ機能の追加                                    */
 /*     1996.01.16  Version2.31                                           */
 /*                   -ﾃﾞｨﾚｸﾄﾘｰのShift+Enterでﾃﾞｨﾚｸﾄﾘｰ･ﾌｫﾙﾀﾞｰのｵｰﾌﾟﾝ機能を*/
 /*                     追加                                              */
 /*                   -指定された関連付けﾌﾟﾛｸﾞﾗﾑが存在しない場合,事前にｴﾗｰ*/
 /*                     ﾒｯｾｰｼﾞを表示し,そのまま実行のOS/2ﾊﾝｸﾞを防止       */
 /*                   -ｶｽﾀﾏｲｽﾞ変更(F2)にINIﾌｧｲﾙの再読み込みを追加         */
 /*                   -ﾏｰｸﾌｧｲﾙ･ｺﾋﾟｰ中に発生したｴﾗｰが表示されないﾊﾞｸﾞを修正*/
 /*     1996.01.27  Version2.32                                           */
 /*                   -ﾏｸﾛ実行ﾌﾟﾛｸﾞﾗﾑについても事前にﾌｧｲﾙ存在ﾁｪｯｸを実施   */
 /*                   -INIﾌｧｲﾙ再読み込みを,任意のﾃﾞｨﾚｸﾄﾘｰで行えるよう修正 */
 /*     1996.09.30  Version2.33                                           */
 /*                   -PC98で文字入力ｳｲﾝﾄﾞｳで←→ｷｰが効かない不具合を修正 */
 /*                   -ｺﾏﾝﾄﾞ･ﾌﾟﾛｾｯｻｰ起動機能の追加(.ｷｰ)                   */
 /*                   -ﾃﾞｨﾚｸﾄﾘｰ下ﾌｧｲﾙ･ｻｲｽﾞ合計機能(@ｷｰ)追加               */
 /*                   -後退(BackSpace)ｷｰで親ﾃﾞｨﾚｸﾄﾘｰに戻る時,ｶｰｿﾙが元の   */
 /*                     ﾃﾞｨﾚｸﾄﾘｰの位置に来るよう修正                      */
 /*                   -ｿｰﾄ(Sｷｰ)に名前･日付･ｻｲｽﾞでのｿｰﾄ･ｵﾌﾟｼｵﾝを追加       */
 /*                   -AXｷｰﾎﾞｰﾄﾞで使えない不具合を修正                    */
 /*                   -ﾏｰｸﾌｧｲﾙのｺﾋﾟｰ中に発生したｴﾗｰを無視してしまうﾊﾞｸﾞ   */
 /*                     を修正(2.30で発生/2.31での修正もれ)               */
 /*                                                                       */
 /* Define Section */
 #define  INCL_DOS
 #define  INCL_VIO
 #define  INCL_KBD
 #define  INCL_DOSFILEMGR
 #define  INCL_DOSSESMGR
 #define  INCL_ERRORS
 #define  INCL_WINWORKPLACE
 #include <os2.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <signal.h>
 #define  BLUE    "\033[00m\033[44m"
 #define  CLEAR   "\033[2J"
 #define  NORMAL  "\033[0m"
 #define  FILE_MAX    4000
 #define  FILE_DISPLEN 250
 #define  ASSOC_MAX    124
 #define  PFK            0
 #define  BACK           8
 #define  ESC           27
 #define  ENTER         13
 #define  MINUS         12
 #define  PLUS          39
 #define  SPACE         57
 #define  PF1           59
 #define  PF2           60
 #define  PF3           61
 #define  PF4           62
 #define  PF5           63
 #define  PF6           64
 #define  PF7           65
 #define  PF8           66
 #define  PF9           67
 #define  PF10          68
 #define  PF11         133
 #define  PF12         134
 #define  ARROW        224
 #define  ARROW_UP      72
 #define  ARROW_DOWN    80
 #define  ARROW_LEFT    75
 #define  ARROW_RIGHT   77
 #define  PAGE_UP       73
 #define  PAGE_DOWN     81
 #define  DELETE        83
 #define  INSERT        82
 #define  HOME          71
 #define  END           79
 #define  KEY1          49
 #define  KEY2          50
 #define  KEY3          51
 #define  KEY4          52
 #define  KEY5          53
 #define  KEY6          54
 #define  KEY7          55
 #define  KEY8          56
 #define  KEY9          57
 #define  KEY0Scan      11
 #define  KEY1Scan       2
 #define  KEY2Scan       3
 #define  KEY3Scan       4
 #define  KEY4Scan       5
 #define  KEY5Scan       6
 #define  CR            '\x0D'
 #define  LF            '\x0A'
 #define  sLF           "\x0A"
 #define  CRLF          "\x0D\x0A"
 #define  CRLFDISP      "\x1B"
 #define  ATTR_SYSTEM   '\x04'
 #define  ATTR_HIDDEN   '\x02'
 #define  ATTR_READONLY '\x01'
 #define  ATTR_SYSTEM_REV   '\xFB'
 #define  ATTR_HIDDEN_REV   '\xFD'
 #define  ATTR_READONLY_REV '\xFE'
 #define  ATTR_DIR      '\x10'
 #define  LCTRL         '\x01\x00'
 #define  LSHIFT        '\x00\x02'
 #define  RSHIFT        '\x00\x01'
 #define  CMDEXEC       CursorInfo.attr=0;VioSetCurType(&CursorInfo,hvio);rc=system(CmdParm);CursorInfo.attr=-1;VioSetCurType(&CursorInfo,hvio);strcpy(PrevFl,FlDis[SelFl].Nm+29);if (!ByPass) QFile();PrevFileSearch();
 #define  KBDINWHILE          do{KbdCharIn(&KeyInfo,IO_WAIT,0);if (KeyInfo.chChar==ESC) break;} while
 #define  MSGBOXKBDINWHILECR  ShowMsgBox();do{KbdCharIn(&KeyInfo,IO_WAIT,0);if (KeyInfo.chChar==ESC) break;} while(KeyInfo.chChar!=ENTER);if (KeyInfo.chChar==ESC){ShowType=0;ShowFileList();}else
 #define  MSGBOXKBDINWHILE    ShowMsgBox();do{KbdCharIn(&KeyInfo,IO_WAIT,0);if (KeyInfo.chChar==ESC) break;} while
 #define  MSGBOXDISP          ShowMsgBox();KbdCharIn(&KeyInfo,IO_WAIT,0);ShowType=0;ShowFileList();
 #define  MSGBOXCLEAR         ShowType=0;ShowFileList();
 #define  MSGBOXINPUTLINE     ShowMsgBox();VioWrtNAttr(WhiteBrightReverse,BoxWide-Indent-6,BoxTop+LineSeq+2,BoxLeft+Indent+3,hvio);VioSetCurPos(BoxTop+LineSeq+2,Col=BoxLeft+Indent+3,hvio);KbdLineIn();if(KeyInfo.chChar==ESC){ShowType=0;ShowFileList();}else
 #define  MSGBOXINPUTLINE2    ShowMsgBox();VioWrtNAttr(WhiteBrightReverse,BoxWide-Indent-6,BoxTop+LineSeq+2,BoxLeft+Indent+3,hvio);VioSetCurPos(BoxTop+LineSeq+2,Col=BoxLeft+Indent+3,hvio);KbdLineIn();
 #define  REDRAWFILELIST      QFile();ShowType=0;ShowFileList();
 #define  SETPREVFILE         strcpy(PrevFl,FlDis[SelFl].Nm+29);QFile();PrevFileSearch();
 #define  SETFILE1STNAMEINPUTLINE memset(InpLine,0,sizeof(InpLine));for (i=0;i<strlen(FlDis[SelFl].Nm+29);++i){if (!memcmp(FlDis[SelFl].Nm+29+i,".",1)) break;memcpy(InpLine+i,FlDis[SelFl].Nm+29+i,1);}InpLineLen=strlen(InpLine);
 #define  SEARCHINIFILEEND1   IniFileEnd=strchr(IniFileIn,' ');if (IniFileEnd==NULL) IniFileEnd=strchr(IniFileIn,'\n');memset(IniFileEnd,0,1);
 #define  SEARCHINIFILEEND2   IniFileEnd=strstr(IniFileIn,"  ");if (IniFileEnd==NULL) IniFileEnd=strchr(IniFileIn,'\n');memset(IniFileEnd,0,1);
 #define  SHOWTOP             StartFl=0;PageNo=1;ShowType=1;ShowFileList();
 #define  INI_GENERAL       1
 #define  INI_EDITOR        2
 #define  INI_EXTENTION     3
 #define  INI_MACRO         4
 #define  RESET             0
 #define  OVERWRITE         1
 #define  TIMECOMP          2
 #define  NOCOPY            3

 /* Working Data Section */
 CHAR        TitleLogo[16][80]={
  "                                                                  ",
  "    ★★★★★,                 ★★★,                           ",
  "    ★,'''''''                 ★,''''                            ",
  "    ★,          ★,          ★,                                 ",
  "    ★★★★,    ★,          ★,                                 ",
  "   ★,''''''    ★, ★★★,     ★★★,    ★,   ★★★,     ★,  ",
  "   ★,     ★,  ★,★''''★,     ''''★,★★★, ★,'''★,  ★★,  ",
  "   ★,          ★,★★★,'          ★, '★,' ★,    ★,  ★,    ",
  "  ★,      ★, ★, ★,'''            ★, ★,   ★,   ★,  ★,     ",
  "  ★,      ★, ★,  ★,             ★,  ★,    ★,  ★,  ★,     ",
  "  ★,     ★,   ★,  ★★★,   ★★★,    ★★,  ★★★★,★,     ",
  "   '       '     '    '''''     '''''      '''    '''''''' '      ",
  "                                                                  ",
  "    Ｖｅｒｓｉｏｎ　２．３３          1996.09  By Ｇeorge         ",
  "                                       (Takahiro Shimada)         ",
  "                                                                  "};
 CHAR        TeatreData[120]=
  "★FileStar★FileStar★FileStar★FileStar★FileStar★FileStar★FileStar★FileStar★FileStar★FileStar★FileStar★FileStar";
 struct _FlDis{
  /*USHORT   DMY;*/
    CHAR     Nm[FILE_DISPLEN];
    BYTE     Atr;
    BYTE     DisAtr[2];
 };
 struct _FlDis FlDis[FILE_MAX];
 CHAR        FlNmSv[FILE_MAX][250],FlTimeSv[FILE_MAX][14];
 BYTE        AtrSv[FILE_MAX];
 CHAR        OriginDir[124],FlstrDirFl[132];
 VIOMODEINFO VioModeInfo;
 KBDKEYINFO  KeyInfo;
 VIOCURSORINFO CursorInfo;
 HVIO        hvio=0;
 UCHAR       c;
 USHORT      i,j,k,ix,jx,RowMax=0,ColMax=0,Row=4,Col,FlCnt,FlCntSv,MarkCnt,StartFl,SelFl,SelFlSv,PageNo,RestCell,ShowType,
             BoxHigh,BoxWide,BoxTop,BoxLeft,SaveRow,InpLineLen,Indent,LineSeq,PrevSearch=0,
             StartupDirErr=0,ByPass=0,OverWrite=0,DirCopy,DirDel,FlMove,FirstDisp=1,AssocFind,SameDrive,
             Loop,Jump=0;
 #define     JUMPDIR RestCell
 PSZ         s,sx;
 CHAR        c_Y='Y';
 CHAR        c_y='y';
 CHAR        c_N='N';
 CHAR        c_n='n';
 CHAR        s_w[2]="w";
 CHAR        c_INF[5]=".INF";
 CHAR        c_EXE[5]=".EXE";
 CHAR        c_CMD[5]=".CMD";
 CHAR        c_BAT[5]=".BAT";
 CHAR        c_COM[5]=".COM";
 CHAR        c_inf[5]=".inf";
 CHAR        c_exe[5]=".exe";
 CHAR        c_cmd[5]=".cmd";
 CHAR        c_bat[5]=".bat";
 CHAR        c_com[5]=".com";
 PBYTE       BoxLineAttr;
 PBYTE       TitleAttr   ="\xB1";
 PBYTE       WallAttr    ="\x1E";
 PBYTE       BlueNull    ="\x11";
 PBYTE       GrayNull    ="\x88";
 PBYTE       GrayBlue    ="\x81";
 PBYTE       GrayBBlue   ="\x8B";
 PBYTE       GrayBrawn   ="\x84";
 PBYTE       GrayBlack   ="\x80";
 PBYTE       GrayWhite   ="\x8F";
 PBYTE       GrayRed     ="\x8C";
 PBYTE       GrayYellow  ="\x8E";
 PBYTE       GrayYellow2 ="\x86";
 PBYTE       GrayGreen   ="\x8A";
 PBYTE       MsgLineAttr ="\x8A";
 PBYTE       YellowGreen ="\x6A";
 PBYTE       YellowBright="\x1E";
 PBYTE       WhiteBright ="\x1F";
 PBYTE       WhiteGray   ="\xF8";
 PBYTE       GreenBright ="\x1A";
 PBYTE       BlueBright  ="\x1B";
 PBYTE       Red         ="\x1C";
 PBYTE       Pink        ="\x1D";
 PBYTE       Grey        ="\x18";
 PBYTE       DarkYellow  ="\x16";
 PBYTE       Black       ="\x10";
 PBYTE       PinkReverse ="\xD1";
 PBYTE       BlackReverse      ="\x0B";
 PBYTE       GreenBrightReverse="\xA1";
 PBYTE       WhiteBrightReverse="\xF1";
 PBYTE       BlueBrightReverse ="\xB1";
 PBYTE       AtrViewFl      ="\x0F";
 PBYTE       AtrViewFlNull  ="\x00";
 PBYTE       AtrViewFlTitle ="\xB1";
 PBYTE       AtrCRLFDISP    ="\x0B";
 CHAR        Title[300];
 CHAR        Footer[300]=" □Ini  F1:説明  F2:設定  F3:終了  F4:□ﾏｸﾛ       F12:Theater";
 ULONG       DriveNo;
 ULONG       DriveMap;
 CHAR        DriveChar[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 CHAR        DriveDis[3]=" :";
 USHORT      DriveDisLen=2;
 ULONG       PathLen=124;
 CHAR        PathDis[300]="\\";
 ULONG       PageDisLen=12;
 CHAR        PageDis[12];
 CHAR        FreeDis[24];
 ULONG       FreeDisLen=24;
 FILEFINDBUF3 FileInfo3;
 LHANDLE     DirHandle=0x0001;
 USHORT      FlMark[FILE_MAX],FlMarkSv[FILE_MAX];
 CHAR        FlCntDis[21]="Files:0000(0000000)K";
 USHORT      FlCntDisLen=19;
 CHAR        MarkCntDis[17]="★0000(0000000)K";
 USHORT      MarkCntDisLen=14;
 ULONG       CurrentSize;
 ULONG       MarkSize;
 CHAR        FlMask[124]="*.*";
 ULONG       FlFindAtr=0x00000037;
 ULONG       FindCnt;
 USHORT      MsgTxtLen[60];
 CHAR        MsgTxt[20][80];
 APIRET      rc;
 STARTDATA   StartData;
 ULONG       SessID;
 PID         ProcID;
 UCHAR       PgmTitle[40];
 UCHAR       FulFlNm[80],FulDirNm[124];
 UCHAR       ObjBuf[256];
 PCH         Hyou="\x95\x5c"; /*"表"*/
 PCH         So  ="\x83\x5c"; /*"ソ"*/
 PCH         Noh ="\x94\x5c"; /*"能"*/
 PCH         Yo  ="\x97\x5c"; /*"予"*/
 PCH         C_BOX0  ="□";
 PCH         C_BOX1  ="■";
 UCHAR       InpLine[124];
 UCHAR       CmdParm[124];
 UCHAR       CurrDir[124]="x";
 UCHAR       PrevDir[124];
 UCHAR       PrevFl[124];
 UCHAR       ObjClassName[124];
 UCHAR       ObjTitle[124];
 UCHAR       ObjSetupString1[1024]="EXENAME=";
 UCHAR       ObjSetupString2[1024]="SHADOWID=";
 UCHAR       ObjLocation[124]="<WP_DESKTOP>";
 ULONG       ObjMode=CO_FAILIFEXISTS;
 HOBJECT     HObj;
 FILE        *Fl;
 UCHAR       IniFileIn[80],*IniFileBuf,*IniFileEnd;
 USHORT      IniSection=0,EditSession=1,EditorNameSet=0,ExecSession=1,AlwaysSort=0,
             AutoClose=1,NoCloseIgnore=0,AssocCnt=0,AssocSession[ASSOC_MAX],LogoTime=5,
             AttrSys,AttrHidden,AttrROnly;
 UCHAR       EditorName[124]="E.EXE",StartupDir[124]="\0",AssocExtention[ASSOC_MAX][124],
             AssocPgmName[ASSOC_MAX][124],AssocParm[ASSOC_MAX][124],
             ShiftPgmName[36][124],ShiftParm[36][124];
 USHORT      LShiftSession[36];
 ULONG       FSInfoLevel1=FSIL_ALLOC,FSInfoLevel2=FSIL_VOLSER;
 UCHAR       FSInfoBuf[40];
 ULONG       FSInfoBufSize=40;
 typedef struct _fsInfo1{
    ULONG    filesysid;            /*ﾌｧｲﾙ･ｼｽﾃﾑID*/
    ULONG    sectornum;            /*割り振り単位あたりのｾｸﾀｰ数*/
    ULONG    unitnum;              /*割り振り単位の数*/
    ULONG    unitavail;            /*利用可能な割り振り単位の数*/
    USHORT   bytesnum;             /*ｾｸﾀｰあたりのﾊﾞｲﾄ数*/
 } fsInfo1;
 typedef fsInfo1 *pFsInfo1;
 pFsInfo1 PFsInfo1;
 typedef struct _fsInfo2{
    ULONG   VolumeSerialNum;
    BYTE    volumelength;
    UCHAR   volumelabel[12];
 } fsInfo2;
 typedef fsInfo2 *pFsInfo2;
 pFsInfo2 PFsInfo2;
 UCHAR       Label[12]="LABELXXXXXX";
 ULONG       OpMode;
 UCHAR       TargetPass[124],TargetName[124],TargetFl[124];
 ULONG       PathInfoLevel;
 FILESTATUS3 PathInfo3;
 UCHAR       ErrMsg[124];
 UCHAR       ViewFlTitle[124]=" StarView Ver1.0    示ﾌｧｲﾙ:";
 USHORT      ViewFlTitleLen=124;
 UCHAR       FlBuff[2][4096],WkBuff[1024];
 USHORT      FlBuffLen=sizeof(FlBuff[0]);
 PSZ         pStart,pFirst;
 USHORT      Rest,FlEnd,AddLine,LineEnd,BufNo,FndCRLF,BufLines[2],FirstBuf,FirstLine,
             FirstSet,LastBuf,LastLine,LastSet;
 PSZ         BufPos[2][2048];
 ULONG       FlPos[2],FlSize;
 UCHAR       ListTxt[11][124]={"1 ","2 ","3 ","4 ","5 ","  ","  ","  ","  ","  ","  "};

 UCHAR       ChangeAttribute_Text_0[36]="ファイルの属性を変更します          ";
 UCHAR       ChangeAttribute_Text_1[36]=" File:                              ";
 UCHAR       ChangeAttribute_Text_2[36]="                                    ";
 UCHAR       ChangeAttribute_Text_3[36]="変更する属性の番号キーを押して下さい";
 UCHAR       ChangeAttribute_Text_4[36]="  1.□システム・ファイル            ";
 UCHAR       ChangeAttribute_Text_5[36]="  2.□隠しファイル                  ";
 UCHAR       ChangeAttribute_Text_6[36]="  3.□リード・オンリー              ";
 UCHAR       ChangeAttribute_Text_7[36]="                                    ";
 UCHAR       ChangeAttribute_Text_8[36]="     Enter:実行    Esc:取消         ";
 UCHAR       ChangeSetup_Text_0 [50]="カスタマズ変更(変更は番号ｷｰ)                      ";
 UCHAR       ChangeSetup_Text_1 [50]="                                                  ";
 UCHAR       ChangeSetup_Text_2 [50]="  0.INIﾌｧｲﾙの再読み込み                           ";
 UCHAR       ChangeSetup_Text_3 [50]="                                                  ";
 UCHAR       ChangeSetup_Text_4 [50]="<ｾｯｼｮﾝ内での一時変更>                             ";
 UCHAR       ChangeSetup_Text_5 [50]="  1.□常にﾌｧｲﾙ名でｿｰﾄする                         ";
 UCHAR       ChangeSetup_Text_6 [50]="  2.□ﾌﾟﾛｸﾞﾗﾑ/ｺﾏﾝﾄﾞ起動時に別ｾｯｼｮﾝを生成する      ";
 UCHAR       ChangeSetup_Text_7 [50]="  3.□ﾌﾟﾛｸﾞﾗﾑ/ｺﾏﾝﾄﾞ終了時にｳｲﾝﾄﾞｳを自動ｸﾛｰｽﾞする  ";
 UCHAR       ChangeSetup_Text_8 [50]="  4.ｴﾃﾞｲﾀｰ名:                                     ";
 UCHAR       ChangeSetup_Text_9 [50]="  5.□ｴﾃﾞｲﾀｰ起動時に別ｾｯｼｮﾝを生成する             ";
 UCHAR       ChangeSetup_Text_10[50]="                                                  ";
 UCHAR       ChangeSetup_Text_11[50]="                            Enter/Esc:戻る        ";
 UCHAR       ChangeWindowSize_Text_0[30]="ウインドウ・サイズを変更します";
 UCHAR       ChangeWindowSize_Text_1[30]="                              ";
 UCHAR       ChangeWindowSize_Text_2[30]="桁数,行数(ﾌﾞﾗﾝｸなし)          ";
 UCHAR       ChangeWindowSize_Text_3[30]="                              ";
 UCHAR       ChangeWindowSize_Text_4[30]="                              ";
 UCHAR       ChangeWindowSize_Text_5[30]="    Enter:実行  Esc:取消      ";
 UCHAR       CommandProcess_Text_0[36]="コマンドプロセッサーを起動します    ";
 UCHAR       CommandProcess_Text_1[36]="起動ｵﾌﾟｼｮﾝを指定して下さい          ";
 UCHAR       CommandProcess_Text_2[36]="                                    ";
 UCHAR       CommandProcess_Text_3[36]="  1.別ｾｯｼｮﾝを生成する(1/Enterｷｰ)    ";
 UCHAR       CommandProcess_Text_4[36]="  2.このｾｯｼｮﾝ内での起動(0/Spaceｷｰ)  ";
 UCHAR       CommandProcess_Text_5[36]="                                    ";
 UCHAR       CommandProcess_Text_6[36]="                   Esc:取消         ";
                                                             
 /* Function Prototype */
 void ChangeAttribute(void);
 void ChangeAttributeDisp(PSZ);
 void ChangeAttributeFunc(USHORT);
 void ChangeDrive(void);
 void ChangeEditorName(void);
 void ChangeSetup(void);
 void ChangeSetupFunc(void);
 void ChangeSetupFuncAlwaysSort(void);
 void ChangeSetupFuncAutoClose(void);
 void ChangeSetupFuncEditorName(void);
 void ChangeSetupFuncEditSession(void);
 void ChangeSetupFuncExecSession(void);
 void ChangeSetupFuncIniRead(void);
 void ChangeWindowSize(void);
 void CommandProcess(void);
 APIRET CopyDirContents(PSZ,PSZ);
 void CreateDir(void);
 APIRET CreateDirFunc(PSZ);
 void CreateDirFuncRc(void);
 void DisplayTheatre(void);
 APIRET DeleteDirContents(PSZ);
 void ExecAssocProgram(void);
 void ExecAssocProgramFunc(USHORT,PSZ);
 void ExecAssocProgramParm(PSZ);
 void ExecCommand(void);
 void ExecProgram(void);
 void FileCopy(void);
 void FileCopyDir(PSZ);
 void FileCopyFl(PSZ,PSZ);
 APIRET FileCopyFunc(PSZ,PSZ,PSZ);
 void FileCopyFuncDisp(PSZ);
 void FileCopyFuncOption(PSZ);
 void FileCopyFuncOptionOv(void);
 void FileCopyFuncOptionRo(PSZ,PSZ);
 APIRET FileCopyFuncTimeComp(PSZ,PSZ,PSZ);
 void FileCopyRc(void);
 void FileXCopy(void);
 void FileDelete(void);
 void FileDeleteFunc(PSZ,BYTE);
 void FileDeleteFuncDisp(PSZ);
 void FileDeleteRc(void);
 void FileEdit(void);
 void FileFind(void);
 void FileFindDir(PSZ);
 void FileFindDisp(PSZ);
 void FileFindMatch(PSZ);
 void FileMark(void);
 void FileMarkAll(void);
 void FileMaskDisp(void);
 void FileMove(void);
 void FileName(void);
 int  FileNameComp(const void *,const void *);
 int  FileNameCompOption(const void *, const void *);
 APIRET FilePathSearch(PSZ);
 void FileSort(void);
 void FuncEvent(void);
 void GetMode(void);
 void GetOriginDir(void);
 void GetParm(void);
 void GoStartupDir(void);
 void IniFileRead(void);
 void InitCustomize(void);
 void InitStartData(void);
 void JumpDir(void);
 void JumpDirDelete(void);
 void JumpDirInsert(void);
 void JumpDirRead(void);
 void JumpHistInsert(void);
 void KbdEvent(void);
 void KbdLineIn(void);
 void KbdLineInHist(void);
 void ListBoxDisp(void);
 void ListBoxDispFunc(void);
 void MacroDisp(void);
 void MacroFunc(void);
 void MacroSetup(void);
 void MacroSetupShift(void);
 void MakeIcon(void);
 void MakeInfIcon(void);
 void MakeInfIconFunc(void);
 void MakePrgIcon(void);
 void MakePrgIconFunc(void);
 void MakeShadowIcon(void);
 void MakeShadowIconFunc(void);
 void MarkFileAttribute(void);
 void MarkFileCopy(void);
 void MarkFileDelete(void);
 void MarkFileExec(void);
 void MarkFileIcon(void);
 void MarkFileMove(void);
 void PrevDirSearch(void);
 void PrevFileSearch(void);
 void QDrive(void);
 void QDriveSize(void);
 void QDir(void);
 void QFile(void);
 void QuitFilestar(void);
 void ReDrawAfterDelete(void);
 void RedrawScreen(void);
 void SameDirCheck(void);
 void SameDriveCheck(void);
 void Serch1Char(void);
 void Serch1CharNg(void);
 void SetFileInfo(void);
 void SetFullDirName(void);
 void SetFullFileName(void);
 void SetupEditor(void);
 void SetupExtention(void);
 void SetupGeneral(void);
 void SetWallColor(void);
 void ShowBottom(void);
 void ShowFileList(void);
 void ShowHelp1(void);
 void ShowHelp2(void);
 void ShowHelp3(void);
 void ShowHelp4(void);
 void ShowHelp5(void);
 void ShowHelp6(void);
 void ShowHelp7(void);
 void ShowMsgBox(void);
 void ShowMsgBoxNull(void);
 void ShowMsgCopyOk(void);
 void ShowMsgCopyStop(void);
 void ShowMsgCrcErr(void);
 void ShowMsgCreateDirErr(void);
 void ShowMsgDeleteErr(void);
 void ShowMsgDeleteDeny(void);
 void ShowMsgDeleteStop(void);
 void ShowMsgDiskFull(void);
 void ShowMsgDriveErr(void);
 void ShowMsgDriveNotReady(void);
 void ShowMsgErr(void);
 void ShowMsgExecErr(void);
 void ShowMsgExecNotF(void);
 void ShowMsgExecOk(void);
 void ShowMsgNotFound(void);
 void ShowMsgFindStop(void);
 void ShowMsgFormatErr(void);
 void ShowMsgIconErr(void);
 void ShowMsgIconNa(void);
 void ShowMsgIconOk(void);
 void ShowMsgIconReg(void);
 void ShowMsgJunpDirErr(void);
 void ShowMsgLocked(void);
 void ShowMsgMoveStop(void);
 void ShowMsgNameErr(void);
 void ShowMsgNameLong(void);
 void ShowMsgNameNg(void);
 void ShowMsgOpenErr(void);
 void ShowMsgParmDirErr(void);
 void ShowMsgPassNg(void);
 void ShowMsgPassNo(void);
 void ShowMsgSameDir(void);
 void ShowMsgSameName(void);
 void ShowMsgSectorNotFound(void);
 void ShowMsgSharedErr(void);
 void ShowMsgStartUpDirErr(void);
 void ShowMsgWriteProtect(void);
 void ShowNewDrive(void);
 void ShowSummarySize(void);
 void ShowTitleWindow(void);
 void SummarySize(PSZ);
 void SummarySizeDisp(PSZ,ULONG);
 void ViewFile(void);
 void ViewFileLine(void);
 void ViewFileNew(void);
 void ViewFilePage(void);
 void ViewFileRead(void);
 void ViewFileRewind(void);
 void ViewInfFile(void);
 void SigTerm(int sig) {DosExit(1,0);}

 /***** Main ******************************************************/
 void main(INT argc,CHAR *argv[])
 {
    if (argc>1) strcpy(FulDirNm,argv[1]);
    else memset(FulDirNm,0,sizeof(FulDirNm));
    signal(SIGINT,SIG_IGN);
    signal(SIGTERM,SigTerm);
    GetOriginDir();
    JumpDirRead();
    GetParm();
    InitCustomize();
    GetMode();
    ShowTitleWindow();
    InitStartData();
    SetWallColor();
    ShowNewDrive();
    if (StartupDirErr) {
       if (FlMove) ShowMsgParmDirErr();
       else ShowMsgStartUpDirErr();
    }
    for(;;){
       KbdCharIn(&KeyInfo,IO_WAIT,0);
       KbdEvent();
    }
 }

/**** ChangeAttribute *******************************************/
 void ChangeAttribute(void)
 {
    BoxLineAttr=GrayBBlue;
    strcpy(MsgTxt[0],ChangeAttribute_Text_0);
    strcpy(MsgTxt[1],ChangeAttribute_Text_1);
    strcpy(MsgTxt[2],ChangeAttribute_Text_2);
    strcpy(MsgTxt[3],ChangeAttribute_Text_3);
    strcpy(MsgTxt[4],ChangeAttribute_Text_4);
    strcpy(MsgTxt[5],ChangeAttribute_Text_5);
    strcpy(MsgTxt[6],ChangeAttribute_Text_6);
    strcpy(MsgTxt[7],ChangeAttribute_Text_7);
    strcpy(MsgTxt[8],ChangeAttribute_Text_8);
    memcpy(MsgTxt[1]+6,FlDis[SelFl].Nm+29,strlen(FlDis[SelFl].Nm+29));
    MsgTxtLen[0]=36; MsgTxtLen[1]=36; MsgTxtLen[2]=36; MsgTxtLen[3]=36;
    MsgTxtLen[4]=36; MsgTxtLen[5]=36; MsgTxtLen[6]=36; MsgTxtLen[7]=36;
    MsgTxtLen[8]=36; MsgTxtLen[9]=0;
    if (FlDis[SelFl].Atr&ATTR_SYSTEM) {memcpy(MsgTxt[4]+4,C_BOX1,2);AttrSys=1;}
    else {memcpy(MsgTxt[4]+4,C_BOX0,2);AttrSys=0;}
    if (FlDis[SelFl].Atr&ATTR_HIDDEN) {memcpy(MsgTxt[5]+4,C_BOX1,2);AttrHidden=1;}
    else {memcpy(MsgTxt[5]+4,C_BOX0,2);AttrHidden=0;}
    if (FlDis[SelFl].Atr&ATTR_READONLY) {memcpy(MsgTxt[6]+4,C_BOX1,2);AttrROnly=1;}
    else {memcpy(MsgTxt[6]+4,C_BOX0,2);AttrROnly=0;}
    ShowMsgBox();
    do{
       KbdCharIn(&KeyInfo,IO_WAIT,0);
       ChangeAttributeFunc(4);
    } while(KeyInfo.chChar!=ESC&&KeyInfo.chChar!=ENTER);
    if (KeyInfo.chChar==ENTER){
       MSGBOXCLEAR
       rc=DosQueryPathInfo(FlDis[SelFl].Nm+29,1,&PathInfo3,sizeof(FILESTATUS3));
       if (AttrSys) PathInfo3.attrFile|=ATTR_SYSTEM; else PathInfo3.attrFile&=ATTR_SYSTEM_REV;
       if (AttrHidden) PathInfo3.attrFile|=ATTR_HIDDEN; else PathInfo3.attrFile&=ATTR_HIDDEN_REV;
       if (AttrROnly) PathInfo3.attrFile|=ATTR_READONLY; else PathInfo3.attrFile&=ATTR_READONLY_REV;
       rc=DosSetPathInfo(FlDis[SelFl].Nm+29,1,&PathInfo3,sizeof(FILESTATUS3),0);
       SETPREVFILE
    }
    MSGBOXCLEAR
 }

/**** ChangeAttributeDisp ***************************************/
 void ChangeAttributeDisp(PSZ FlNm)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0],"ファイル属性の変更中です",24);
    memset(MsgTxt[1],0,24);
    memcpy(MsgTxt[1]+1,FlNm,strlen(FlNm));
    MsgTxtLen[0]=24; MsgTxtLen[1]=24; MsgTxtLen[2]=0;
    if (FirstDisp) {ShowMsgBox();FirstDisp=0;}
    else if (1<BoxHigh-4) VioWrtCharStrAtt(MsgTxt[1],BoxWide-3,BoxTop+3,BoxLeft+3,BoxLineAttr,hvio);
 }

/**** ChangeAttributeFunc ***************************************/
 void ChangeAttributeFunc(USHORT Ix)
 {
    USHORT Ix2=Ix+1,Ix3=Ix+2;
    switch(KeyInfo.chScan){
       case KEY1Scan:
          if (AttrSys){AttrSys=0;memcpy(MsgTxt[Ix]+4,C_BOX0,2);}
          else {AttrSys=1;memcpy(MsgTxt[Ix]+4,C_BOX1,2);}
          if (Ix<BoxHigh-4) VioWrtCharStrAtt(MsgTxt[Ix]+4,2,BoxTop+2+Ix,BoxLeft+7,BoxLineAttr,hvio);
          break;
       case KEY2Scan:
          if (AttrHidden){AttrHidden=0;memcpy(MsgTxt[Ix2]+4,C_BOX0,2);}
          else {AttrHidden=1;memcpy(MsgTxt[Ix2]+4,C_BOX1,2);}
          if (Ix2<BoxHigh-4) VioWrtCharStrAtt(MsgTxt[Ix2]+4,2,BoxTop+3+Ix,BoxLeft+7,BoxLineAttr,hvio);
          break;
       case KEY3Scan:
          if (AttrROnly){AttrROnly=0;memcpy(MsgTxt[Ix3]+4,C_BOX0,2);}
          else {AttrROnly=1;memcpy(MsgTxt[Ix3]+4,C_BOX1,2);}
          if (Ix3<BoxHigh-4) VioWrtCharStrAtt(MsgTxt[Ix3]+4,2,BoxTop+4+Ix,BoxLeft+7,BoxLineAttr,hvio);
          break;
       default:;
    }
 }

/**** ChangeDrive ***********************************************/
 void ChangeDrive(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"  別のドライブへ移ります  ",26);
    memcpy(MsgTxt[1],"ドライブ文字を押して下さい",26);
    MsgTxtLen[0]=26; MsgTxtLen[1]=26; MsgTxtLen[2]=0;
    MSGBOXKBDINWHILE (KeyInfo.chChar<'A'
                  || (KeyInfo.chChar>'Z'&&KeyInfo.chChar<'a')
                  || KeyInfo.chChar>'z');
    if (KeyInfo.chChar==ESC) {MSGBOXCLEAR}
    else {
       MSGBOXCLEAR
       DriveNo=(KeyInfo.chChar<'a'?KeyInfo.chChar-64:KeyInfo.chChar-96);
       rc=DosSetDefaultDisk(DriveNo);
       switch(rc){
          case NO_ERROR: ShowNewDrive(); break;
          default: ShowMsgDriveErr();
       }
    }
 }

/**** ChangeEditorName ******************************************/
 void ChangeEditorName(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ｴﾃﾞｨﾀｰ･ﾌﾟﾛｸﾞﾗﾑ名を入力して下さい        ",40);
    memset(MsgTxt[1],0,40);
    memset(MsgTxt[2],0,40);
    memcpy(MsgTxt[3],"       Enter:実行     Esc:取消          ",40);
    MsgTxtLen[0]=40; MsgTxtLen[1]=40; MsgTxtLen[2]=40; MsgTxtLen[3]=40;
    MsgTxtLen[4]=0;
    memset(InpLine,0,sizeof(InpLine));
    strcpy(InpLine,EditorName);
    Indent=0;LineSeq=1;MSGBOXINPUTLINE2
    {
       if(KeyInfo.chChar!=ESC) strcpy(EditorName,InpLine);
    }
 }

/**** ChangeSetup ***********************************************/
 void ChangeSetup(void)
 {
    BoxLineAttr=GrayYellow;
    strcpy(MsgTxt[0],ChangeSetup_Text_0);
    strcpy(MsgTxt[1],ChangeSetup_Text_1);
    strcpy(MsgTxt[2],ChangeSetup_Text_2);
    strcpy(MsgTxt[3],ChangeSetup_Text_3);
    strcpy(MsgTxt[4],ChangeSetup_Text_4);
    strcpy(MsgTxt[5],ChangeSetup_Text_5);
    strcpy(MsgTxt[6],ChangeSetup_Text_6);
    strcpy(MsgTxt[7],ChangeSetup_Text_7);
    strcpy(MsgTxt[8],ChangeSetup_Text_8);
    strcpy(MsgTxt[9],ChangeSetup_Text_9);
    strcpy(MsgTxt[10],ChangeSetup_Text_10);
    strcpy(MsgTxt[11],ChangeSetup_Text_11);
    if (AlwaysSort) memcpy(MsgTxt[5]+4,C_BOX1,2);
    else memcpy(MsgTxt[5]+4,C_BOX0,2);
    if (ExecSession) memcpy(MsgTxt[6]+4,C_BOX1,2);
    else memcpy(MsgTxt[6]+4,C_BOX0,2);
    if (AutoClose) memcpy(MsgTxt[7]+4,C_BOX1,2);
    else memcpy(MsgTxt[7]+4,C_BOX0,2);
    memcpy(MsgTxt[8]+13,EditorName,strlen(EditorName));
    if (EditSession) memcpy(MsgTxt[9]+4,C_BOX1,2);
    else memcpy(MsgTxt[9]+4,C_BOX0,2);
    MsgTxtLen[0]=50; MsgTxtLen[1]=50; MsgTxtLen[2]=50; MsgTxtLen[3]=50;
    MsgTxtLen[4]=50; MsgTxtLen[5]=50; MsgTxtLen[6]=50; MsgTxtLen[7]=50;
    MsgTxtLen[8]=50; MsgTxtLen[9]=50; MsgTxtLen[10]=50; MsgTxtLen[11]=50;
    MsgTxtLen[12]=0;
    ShowMsgBox();
    do{
       KbdCharIn(&KeyInfo,IO_WAIT,0);
       ChangeSetupFunc();
    } while(KeyInfo.chChar!=ESC&&KeyInfo.chChar!=ENTER); {MSGBOXCLEAR}
 }

/**** ChangeSetupFunc *******************************************/
 void ChangeSetupFunc(void)
 {
    switch(KeyInfo.chScan){
       case KEY0Scan: ChangeSetupFuncIniRead(); break;
       case KEY1Scan: ChangeSetupFuncAlwaysSort(); break;
       case KEY2Scan: ChangeSetupFuncExecSession(); break;
       case KEY3Scan: ChangeSetupFuncAutoClose(); break;
       case KEY4Scan: ChangeSetupFuncEditorName(); break;
       case KEY5Scan: ChangeSetupFuncEditSession(); break;
       default:;
    }
 }

/**** ChangeSetupFuncAlwaysSort *********************************/
 void ChangeSetupFuncAlwaysSort(void)
 {
    if (AlwaysSort){AlwaysSort=0; memcpy(MsgTxt[5]+4,C_BOX0,2);}
    else {AlwaysSort=1; memcpy(MsgTxt[5]+4,C_BOX1,2);}
    if (4<BoxHigh-4) VioWrtCharStrAtt(MsgTxt[5],BoxWide-3,BoxTop+2+5,BoxLeft+3,BoxLineAttr,hvio);
 }

/**** ChangeSetupFuncAutoClose **********************************/
 void ChangeSetupFuncAutoClose(void)
 {
    if (AutoClose){AutoClose=0; memcpy(MsgTxt[7]+4,C_BOX0,2);}
    else {AutoClose=1; memcpy(MsgTxt[7]+4,C_BOX1,2);}
    if (6<BoxHigh-4) VioWrtCharStrAtt(MsgTxt[7],BoxWide-3,BoxTop+2+7,BoxLeft+3,BoxLineAttr,hvio);
 }

/**** ChangeSetupFuncEditorName *********************************/
 void ChangeSetupFuncEditorName(void)
 {
    MSGBOXCLEAR
    ChangeEditorName();
    memcpy(MsgTxt[8]+13,EditorName,strlen(EditorName));
    ChangeSetup();
 }

/**** ChangeSetupFuncEditSession ********************************/
 void ChangeSetupFuncEditSession(void)
 {
    if (EditSession){EditSession=0; memcpy(MsgTxt[9]+4,C_BOX0,2);}
    else {EditSession=1; memcpy(MsgTxt[9]+4,C_BOX1,2);}
    if (9<BoxHigh-4) VioWrtCharStrAtt(MsgTxt[9],BoxWide-3,BoxTop+2+9,BoxLeft+3,BoxLineAttr,hvio);
 }

/**** ChangeSetupFuncExecSession ********************************/
 void ChangeSetupFuncExecSession(void)
 {
    if (ExecSession){ExecSession=0; memcpy(MsgTxt[6]+4,C_BOX0,2);}
    else {ExecSession=1; memcpy(MsgTxt[6]+4,C_BOX1,2);}
    if (5<BoxHigh-4) VioWrtCharStrAtt(MsgTxt[6],BoxWide-3,BoxTop+2+6,BoxLeft+3,BoxLineAttr,hvio);
 }

/**** ChangeSetupFuncIniRead ************************************/
 void ChangeSetupFuncIniRead(void)
 {
    MSGBOXCLEAR
    IniFileRead();
    ChangeSetup();
 }

/**** ChangeWindowSize ******************************************/
 void ChangeWindowSize(void)
 {
    BoxLineAttr=GrayBBlue;
    strcpy(MsgTxt[0],ChangeWindowSize_Text_0);
    strcpy(MsgTxt[1],ChangeWindowSize_Text_1);
    strcpy(MsgTxt[2],ChangeWindowSize_Text_2);
    strcpy(MsgTxt[3],ChangeWindowSize_Text_3);
    strcpy(MsgTxt[4],ChangeWindowSize_Text_4);
    strcpy(MsgTxt[5],ChangeWindowSize_Text_5);
    MsgTxtLen[0]=30; MsgTxtLen[1]=30; MsgTxtLen[2]=30; MsgTxtLen[3]=30;
    MsgTxtLen[4]=30; MsgTxtLen[5]=30; MsgTxtLen[6]=0;
    memset(InpLine,0,sizeof(InpLine));
    sprintf(InpLine,"%d,%d\0",ColMax,RowMax);
    Indent=0;LineSeq=3;MSGBOXINPUTLINE
    {
       memcpy(CmdParm,"mode co",7);
       memcpy(CmdParm+7,InpLine,strlen(InpLine)+1);
       CMDEXEC
       GetMode();
       RedrawScreen();
    }
 }

/**** CommandProcess ******************************************/
 void CommandProcess(void)
 {
    BoxLineAttr=GrayBBlue;
    strcpy(MsgTxt[0],CommandProcess_Text_0);
    strcpy(MsgTxt[1],CommandProcess_Text_1);
    strcpy(MsgTxt[2],CommandProcess_Text_2);
    strcpy(MsgTxt[3],CommandProcess_Text_3);
    strcpy(MsgTxt[4],CommandProcess_Text_4);
    strcpy(MsgTxt[5],CommandProcess_Text_5);
    strcpy(MsgTxt[6],CommandProcess_Text_6);
    MsgTxtLen[0]=36; MsgTxtLen[1]=36; MsgTxtLen[2]=36; MsgTxtLen[3]=36;
    MsgTxtLen[4]=36; MsgTxtLen[5]=36; MsgTxtLen[6]=36; MsgTxtLen[7]=0;
    ShowMsgBox();
    do{
       KbdCharIn(&KeyInfo,IO_WAIT,0);
       ChangeAttributeFunc(4);
    } while(KeyInfo.chChar!=ESC&&KeyInfo.chChar!=ENTER
          &&KeyInfo.chChar!=' '&&KeyInfo.chChar!='1'&&KeyInfo.chChar!='0');
    MSGBOXCLEAR
    switch(KeyInfo.chChar){
       case '1': case ENTER:
          memcpy(FulFlNm,"CMD.EXE",8);
          memset(CmdParm,0,1);
          StartData.PgmTitle   = InpLine;
          StartData.PgmName    = FulFlNm;
          StartData.PgmInputs  = CmdParm;
          StartData.PgmControl = SSF_CONTROL_VISIBLE;
          memset(StartData.ObjectBuffer,0,sizeof(StartData.ObjectBuffer));
          rc = DosStartSession(&StartData, &SessID, &ProcID); MSGBOXCLEAR
          switch(rc){
             case NO_ERROR: break;
             default: ShowMsgExecErr(); break;
          }
          break;
       case '0': case ' ':
          strcpy(CmdParm,"CMD.EXE");
          puts(CLEAR); CMDEXEC
          RedrawScreen();
          QDriveSize();
          break;
       default: break;
    }
 }

/**** CopyDirContents *****************************************/
 APIRET CopyDirContents(PSZ SourceDir,PSZ TargetDir)
 {
    APIRET rca; int ia; UCHAR TargetNewDir[124]; ByPass=0;
    rca=DosSetCurrentDir(SourceDir);if (rca) return(rca);
    memcpy(TargetNewDir,TargetDir,i=strlen(TargetDir));
    if (TargetNewDir[i-1]!='\\') {memset(TargetNewDir+i,'\\',1);++i;}
    memcpy(TargetNewDir+i,SourceDir,strlen(SourceDir)+1);
    rca=DosQueryPathInfo(TargetNewDir,1,&PathInfo3,sizeof(FILESTATUS3));
    if (rca) rca=DosCreateDir(TargetNewDir,0);
    else if (!(PathInfo3.attrFile&=ATTR_DIR)) rca=ERROR_PATH_NOT_FOUND;
    if (!rca){
       FileCopyFuncDisp(" ");
       QFile();
    }
    for (ia=1;ia<FlCnt&&!rca&&KeyInfo.chChar!=ESC&&!ByPass;++ia) {
       KbdCharIn(&KeyInfo,IO_NOWAIT,0);
       memset(MsgTxt[1],0,sizeof(MsgTxt[1]));
       memcpy(MsgTxt[1]+1,FlDis[ia].Nm+29,strlen(FlDis[ia].Nm+29));
       if (MsgTxtLen[1]+3>BoxWide) j=BoxWide-3; else j=MsgTxtLen[1];
       if (1<BoxHigh-4) VioWrtCharStrAtt(MsgTxt[1],j,BoxTop+2+1,BoxLeft+3,BoxLineAttr,hvio);
       if (FlDis[ia].Atr&ATTR_DIR) rca=CopyDirContents(FlDis[ia].Nm+29,TargetNewDir);
       else rca=FileCopyFunc(FlDis[ia].Nm+29,FlDis[ia].Nm+13,TargetNewDir);
       QDriveSize();
    }
    DosSetCurrentDir("..");QFile();return(rca);
 }

/**** CreateDir *************************************************/
 void CreateDir(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ディレクトリ－を作成します　　　　　",36);
    memset(MsgTxt[1],0,36);
    memcpy(MsgTxt[2],"ディレクトリ－名                    ",36);
    memset(MsgTxt[3],0,36);
    memset(MsgTxt[4],0,36);
    memcpy(MsgTxt[5],"      Enter:実行    Esc:取消        ",36);
    MsgTxtLen[0]=36; MsgTxtLen[1]=36; MsgTxtLen[2]=36; MsgTxtLen[3]=36;
    MsgTxtLen[4]=36; MsgTxtLen[5]=36; MsgTxtLen[6]=0;
    memset(InpLine,0,sizeof(InpLine));
    Indent=0;LineSeq=3;MSGBOXINPUTLINE
    {
       MSGBOXCLEAR
       if (!strlen(InpLine)) {ShowMsgNameNg();return;}
       if (!DosQueryPathInfo(InpLine,1,&PathInfo3,sizeof(FILESTATUS3))) {ShowMsgSameName();return;}
       rc=CreateDirFunc(InpLine);
       CreateDirFuncRc();
    }
 }

/**** CreateDirFunc *********************************************/
 APIRET CreateDirFunc(PSZ pDirName)
 {
    PSZ s1,s2;
    UCHAR wDirNm[124];
    memset(wDirNm,0,sizeof(wDirNm));
    if (s1=strstr(pDirName,":\\")) s1+=2;
    else if (s1=strchr(pDirName,':')) ++s1;
    else s1=pDirName;
    for (;s2;){
       s2=strchr(s1,'\\');
       if (s2) {memcpy(wDirNm,pDirName,s2-pDirName);s1=s2+1;}
       else strcpy(wDirNm,pDirName);
       rc=DosQueryPathInfo(wDirNm,1,&PathInfo3,sizeof(FILESTATUS3));
       switch(rc){
          case NO_ERROR: break;
          case ERROR_FILE_NOT_FOUND: case ERROR_PATH_NOT_FOUND:
             rc=DosCreateDir(wDirNm,0); break;
          default:;
       }
    }
 }

/**** CreateDirFuncRc *******************************************/
 void CreateDirFuncRc(void)
 {
    switch(rc){
       case NO_ERROR: case ERROR_FILE_NOT_FOUND:
          SETPREVFILE MSGBOXCLEAR rc=0; break;
       case ERROR_WRITE_PROTECT: ShowMsgWriteProtect(); break;
       case ERROR_INVALID_NAME: case ERROR_PATH_NOT_FOUND:
          ShowMsgNameNg(); break;
       case ERROR_FILENAME_EXCED_RANGE: ShowMsgNameLong(); break;
       case ERROR_DISK_FULL: ShowMsgDiskFull(); break;
       default: ShowMsgErr();
    }
 }

/**** DisplayTheatre ********************************************/
 void DisplayTheatre(void)
 {
    int t=0;
    UCHAR Attr;
    for (i=0,j=0,k=0;KeyInfo.chChar!=ESC;++i,++j){
       if (i==RowMax) {i=0;++t;
          if (t>24) {t=0;++k;}
          if (k==16) k=0;
       }
       if (j==16) j=0;
       Attr=k*16+j;
       VioWrtCharStrAtt(TeatreData,ColMax,i,0,&Attr,hvio);
       KbdCharIn(&KeyInfo,IO_NOWAIT,0);
    }
    RedrawScreen();
 }

/**** DeleteDirContents *****************************************/
 APIRET DeleteDirContents(PSZ DirName)
 {
    APIRET rca; int ia;
    
    DosSetCurrentDir(DirName);
    QFile();
    for (ia=1,rca=0;ia<FlCnt&&!rca&&KeyInfo.chChar!=ESC;++ia) {
       KbdCharIn(&KeyInfo,IO_NOWAIT,0);
       memset(MsgTxt[1],0,sizeof(MsgTxt[1]));
       memcpy(MsgTxt[1]+1,FlDis[ia].Nm+29,strlen(FlDis[ia].Nm+29));
       if (MsgTxtLen[1]+3>BoxWide) j=BoxWide-3; else j=MsgTxtLen[1];
       if (1<BoxHigh-4) VioWrtCharStrAtt(MsgTxt[1],j,BoxTop+2+1,BoxLeft+3,BoxLineAttr,hvio);
       if (FlDis[ia].Atr&ATTR_DIR){
          rca=DeleteDirContents(FlDis[ia].Nm+29);ia=1;
          rca=DosDeleteDir(FlDis[ia].Nm+29);
       }
       else {
          if (FlDis[ia].Atr&ATTR_READONLY){
             rc=DosQueryPathInfo(FlDis[ia].Nm+29,1,&PathInfo3,sizeof(FILESTATUS3));
             PathInfo3.attrFile&=ATTR_READONLY_REV;
             rc=DosSetPathInfo(FlDis[ia].Nm+29,1,&PathInfo3,sizeof(FILESTATUS3),0);
          }
          rca=DosDelete(FlDis[ia].Nm+29);
          if (rca) strcpy(InpLine,FlDis[ia].Nm+29);
       }
       QDriveSize();
    }
    DosSetCurrentDir("..");QFile();return(rca);
 }

/**** ExecCommand ************************************************/
 void ExecCommand(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"コマンドの実行(CMD.EXE呼び出し)をします     ",44);
    memcpy(MsgTxt[1],"  □別ｾｯｼｮﾝを生成する                       ",44);
    memcpy(MsgTxt[2],"  □終了時自動ｸﾛｰｽﾞ(別ｾｯｼｮﾝ時有効)          ",44);
    memset(MsgTxt[3],0,44);
    memcpy(MsgTxt[4],"コマンドを入力して下さい                    ",44);
    memset(MsgTxt[5],0,44);
    memset(MsgTxt[6],0,44);
    memcpy(MsgTxt[7],"        Enter:実行    Esc:取消              ",44);
    if (ExecSession) memcpy(MsgTxt[1]+2,C_BOX1,2);
    else memcpy(MsgTxt[1]+2,C_BOX0,2);
    if (AutoClose) memcpy(MsgTxt[2]+2,C_BOX1,2);
    else memcpy(MsgTxt[2]+2,C_BOX0,2);
    MsgTxtLen[0]=44; MsgTxtLen[1]=44; MsgTxtLen[2]=44; MsgTxtLen[3]=44;
    MsgTxtLen[4]=44; MsgTxtLen[5]=44; MsgTxtLen[6]=44; MsgTxtLen[7]=44;
    MsgTxtLen[8]=0;
    memset(InpLine,0,sizeof(InpLine));
    strcpy(InpLine,FlDis[SelFl].Nm+29);
    Indent=0;LineSeq=5;MSGBOXINPUTLINE
    {
       if (ExecSession){
          memcpy(FulFlNm,"CMD.EXE",8);
          memcpy(CmdParm,"/C ",3);
          memcpy(CmdParm+3,InpLine,strlen(InpLine)+1);
          StartData.PgmTitle   = InpLine;
          StartData.PgmName    = FulFlNm;
          StartData.PgmInputs  = CmdParm;
          if (AutoClose) StartData.PgmControl = SSF_CONTROL_VISIBLE;
          else StartData.PgmControl = SSF_CONTROL_VISIBLE|SSF_CONTROL_NOAUTOCLOSE;
          memset(StartData.ObjectBuffer,0,sizeof(StartData.ObjectBuffer));
          rc = DosStartSession(&StartData, &SessID, &ProcID); MSGBOXCLEAR
          switch(rc){
             case NO_ERROR: ShowMsgExecOk(); break;
             case ERROR_FILE_NOT_FOUND: ShowMsgExecNotF(); break;
             default: ShowMsgExecErr(); break;
          }
       }
       else{
          memcpy(CmdParm,"CMD.EXE /C ",11);
          memcpy(CmdParm+11,InpLine,strlen(InpLine)+1);
          puts(CLEAR); CMDEXEC
          RedrawScreen();
       }
       QDriveSize();
    }
 }

/**** ExecAssocProgram ******************************************/
 void ExecAssocProgram(void)
 {
    for (ix=0;ix<AssocCnt;++ix)
      if (strstr(FlDis[SelFl].Nm+29,AssocExtention[ix])) break;
    if (ix==AssocCnt) return;
    ExecAssocProgramParm(AssocParm[ix]);
    AssocFind=1;
    if (ByPass) {ExecAssocProgramFunc(AssocSession[ix],AssocPgmName[ix]);return;}
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"拡張子に関連付けられたプログラムを実行します          ",54);
    memset(MsgTxt[1],0,54);
    memcpy(MsgTxt[2],"  Pgm :                                               ",54);
    memcpy(MsgTxt[3],"  Parm:                                               ",54);
    memcpy(MsgTxt[4],"  □別ｾｯｼｮﾝを生成する                                 ",54);
    memcpy(MsgTxt[5],"  □終了時自動ｸﾛｰｽﾞ(別ｾｯｼｮﾝ時有効)                    ",54);
    memset(MsgTxt[6],0,54);
    memcpy(MsgTxt[7],"             Enter:実行      Esc:取消                 ",54);
    memcpy(MsgTxt[2]+8,AssocPgmName[ix],strlen(AssocPgmName[ix]));
    memcpy(MsgTxt[3]+8,ObjTitle,strlen(ObjBuf));
    if (AssocSession[ix]) memcpy(MsgTxt[4]+2,C_BOX1,2);
    else memcpy(MsgTxt[4]+2,C_BOX0,2);
    if (AutoClose) memcpy(MsgTxt[5]+2,C_BOX1,2);
    else memcpy(MsgTxt[5]+2,C_BOX0,2);
    MsgTxtLen[0]=54; MsgTxtLen[1]=54; MsgTxtLen[2]=54; MsgTxtLen[3]=54;
    MsgTxtLen[4]=54; MsgTxtLen[5]=54; MsgTxtLen[6]=54; MsgTxtLen[7]=54;
    MsgTxtLen[8]=0;
    MSGBOXKBDINWHILECR
    {
       MSGBOXCLEAR
       rc=DosQueryPathInfo(AssocPgmName[ix],1,&PathInfo3,sizeof(FILESTATUS3));
       if (rc) rc=FilePathSearch(AssocPgmName[ix]);/*絶対名がFulFlNmへ*/
       if (rc){
          strcpy(StartData.ObjectBuffer,AssocPgmName[ix]);
          ShowMsgExecNotF();return;
       }
       ExecAssocProgramFunc(AssocSession[ix],AssocPgmName[ix]);
    }
 }

/**** ExecAssocProgramFunc **************************************/
 void ExecAssocProgramFunc(USHORT session,PSZ pPgmName)
 {
    if (session){
       if (strstr(pPgmName,c_CMD)||strstr(pPgmName,c_cmd)
         ||strstr(pPgmName,c_BAT)||strstr(pPgmName,c_bat)){
          memcpy(FulFlNm,"CMD.EXE",8);
          memcpy(CmdParm,"/C ",i=3);
          memcpy(CmdParm+i,pPgmName,j=strlen(pPgmName));
          memset(CmdParm+(i+=j),' ',1);
          memcpy(CmdParm+(++i),ObjBuf,strlen(ObjBuf)+1);
          StartData.PgmTitle   = pPgmName;
          StartData.PgmName    = FulFlNm;
          StartData.PgmInputs  = CmdParm;
          if (AutoClose) StartData.PgmControl = SSF_CONTROL_VISIBLE;
          else StartData.PgmControl = SSF_CONTROL_VISIBLE|SSF_CONTROL_NOAUTOCLOSE;
       }
       else{
          strcpy(CmdParm,ObjBuf);
          StartData.PgmTitle   = ObjTitle;
          StartData.PgmName    = pPgmName;
          StartData.PgmInputs  = CmdParm;
          if (AutoClose) StartData.PgmControl = SSF_CONTROL_VISIBLE;
          else StartData.PgmControl = SSF_CONTROL_VISIBLE|SSF_CONTROL_NOAUTOCLOSE;
       }
       memset(StartData.ObjectBuffer,0,sizeof(StartData.ObjectBuffer));
       rc=DosStartSession(&StartData,&SessID,&ProcID);
       switch(rc){
          case NO_ERROR: if (!ByPass) ShowMsgExecOk(); break;
          case ERROR_FILE_NOT_FOUND: ShowMsgExecNotF(); break;
          default: ShowMsgExecErr(); break;
       }
    }
    else{
       memcpy(CmdParm,pPgmName,i=strlen(pPgmName));
       memset(CmdParm+i,' ',1);
       memcpy(CmdParm+i+1,ObjBuf,strlen(ObjBuf)+1);
       puts(CLEAR); CMDEXEC if (!ByPass) RedrawScreen();
       FlMove=1;/*MarkFileExec終了処理のためのﾌﾗｸﾞ*/
    }
    if (!ByPass) QDriveSize();
 }

/**** ExecAssocProgramParm **************************************/
 void ExecAssocProgramParm(PSZ pParm)
 {
    /*ObjBuf,ObjTitleにﾊﾟﾗﾒｰﾀをｾｯﾄ.前者のﾌｧｲﾙ名は絶対名*/
    SetFullFileName();
    memset(ObjBuf,0,sizeof(ObjBuf)); memset(ObjTitle,0,sizeof(ObjTitle));
    memcpy(ObjBuf,pParm,strlen(pParm)+1);
    memcpy(ObjTitle,pParm,strlen(pParm)+1);
    if (!strlen(ObjBuf)){
       memcpy(ObjBuf,FulFlNm,strlen(FulFlNm)+1);
       memcpy(ObjTitle,FlDis[SelFl].Nm+29,strlen(FlDis[SelFl].Nm+29)+1);
    }
    /*ﾊﾟﾗﾒｰﾀ指定あり*/
    else if (s=strstr(ObjBuf,"&F")){
       memcpy(CmdParm,s+2,strlen(s+2)+1);
       memcpy(s,FulFlNm,i=strlen(FulFlNm)+1);
       if (j=strlen(CmdParm)) memcpy(s+i-1,CmdParm,j);
       s=strstr(ObjTitle,"&F");
       memcpy(s,FlDis[SelFl].Nm+29,i=strlen(FlDis[SelFl].Nm+29)+1);
       if (j=strlen(CmdParm)) memcpy(s+i-1,CmdParm,j);
    }
 }

/**** ExecProgram ***********************************************/
 void ExecProgram(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"プログラムを実行します            ",34);
    memset(MsgTxt[1],0,34);
    memcpy(MsgTxt[2],"  □別ｾｯｼｮﾝを生成する             ",34);
    memcpy(MsgTxt[3],"  □終了時自動ｸﾛｰｽﾞ(別ｾｯｼｮﾝ時有効)",34);
    memset(MsgTxt[4],0,34);
    memcpy(MsgTxt[5],"パラメータが必要なら入力して下さい",34);
    memset(MsgTxt[6],0,34);
    memset(MsgTxt[7],0,34);
    memcpy(MsgTxt[8],"     Enter:実行  Esc:取消         ",34);
    memcpy(MsgTxt[1]+2,FlDis[SelFl].Nm+29,strlen(FlDis[SelFl].Nm+29));
    if (ExecSession) memcpy(MsgTxt[2]+2,C_BOX1,2);
    else memcpy(MsgTxt[2]+2,C_BOX0,2);
    if (AutoClose) memcpy(MsgTxt[3]+2,C_BOX1,2);
    else memcpy(MsgTxt[3]+2,C_BOX0,2);
    MsgTxtLen[0]=34; MsgTxtLen[1]=34; MsgTxtLen[2]=34; MsgTxtLen[3]=34;
    MsgTxtLen[4]=34; MsgTxtLen[5]=34; MsgTxtLen[6]=34; MsgTxtLen[7]=34;
    MsgTxtLen[8]=34; MsgTxtLen[9]=0;
    memset(InpLine,0,sizeof(InpLine));
    Indent=0;LineSeq=6;MSGBOXINPUTLINE
    {
       if (ExecSession&&!AutoClose) if
          ((!NoCloseIgnore
              &&(strstr(FlDis[SelFl].Nm+29,c_EXE)||strstr(FlDis[SelFl].Nm+29,c_exe)) )
           ||(strstr(FlDis[SelFl].Nm+29,c_COM)||strstr(FlDis[SelFl].Nm+29,c_com)) ){
          MSGBOXCLEAR
          BoxLineAttr=GrayYellow;
          memcpy(MsgTxt[0],"注意!!                                     ",43);
          memcpy(MsgTxt[1],"別ｾｯｼｮﾝを生成しますが終了時自動ｸﾛｰｽﾞがOFFに",43);
          memcpy(MsgTxt[2],"なっています.DOSﾌﾟﾛｸﾞﾗﾑの場合は終了後にｼｽﾃﾑ",43);
          memcpy(MsgTxt[3],"がﾊﾝｸﾞします.                              ",43);
          memcpy(MsgTxt[4],"必要に応じ自動ｸﾛｰｽﾞの設定を変更して下さい. ",43);
          memcpy(MsgTxt[5],"                                           ",43);
          memcpy(MsgTxt[6],"このままﾌﾟﾛｸﾞﾗﾑの実行をしますか？          ",43);
          memcpy(MsgTxt[7],"                                           ",43);
          memcpy(MsgTxt[8],"       Ｙ:yes(Enter)     Ｎ:no(Esc)        ",43);
          MsgTxtLen[0]=43; MsgTxtLen[1]=43; MsgTxtLen[2]=43; MsgTxtLen[3]=43;
          MsgTxtLen[4]=43; MsgTxtLen[5]=43; MsgTxtLen[6]=43; MsgTxtLen[7]=43;
          MsgTxtLen[8]=43; MsgTxtLen[9]=0;
          MSGBOXKBDINWHILE(KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y
                        && KeyInfo.chChar!=c_N&&KeyInfo.chChar!=c_n
                        &&KeyInfo.chChar!=ENTER);
          if (KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y&&KeyInfo.chChar!=ENTER) {MSGBOXCLEAR return;}
       }
       if (ExecSession){
          if (strstr(FlDis[SelFl].Nm+29,c_CMD)||strstr(FlDis[SelFl].Nm+29,c_cmd)
            ||strstr(FlDis[SelFl].Nm+29,c_BAT)||strstr(FlDis[SelFl].Nm+29,c_bat)){
             memcpy(FulFlNm,"CMD.EXE",8);
             memcpy(CmdParm,"/C ",3);
             memcpy(CmdParm+3,FlDis[SelFl].Nm+29,j=strlen(FlDis[SelFl].Nm+29));
             memset(CmdParm+3+j,' ',1);
             memcpy(CmdParm+4+j,InpLine,strlen(InpLine)+1);
             StartData.PgmTitle   = FlDis[SelFl].Nm+29;
             StartData.PgmName    = FulFlNm;
             StartData.PgmInputs  = CmdParm;
             if (AutoClose) StartData.PgmControl = SSF_CONTROL_VISIBLE;
             else StartData.PgmControl = SSF_CONTROL_VISIBLE|SSF_CONTROL_NOAUTOCLOSE;
          }
          else{
             SetFullFileName();
             StartData.PgmTitle   = FlDis[SelFl].Nm+29;
             StartData.PgmName    = FulFlNm;
             StartData.PgmInputs  = InpLine;
             if (AutoClose) StartData.PgmControl = SSF_CONTROL_VISIBLE;
             else StartData.PgmControl = SSF_CONTROL_VISIBLE|SSF_CONTROL_NOAUTOCLOSE;
          }
          memset(StartData.ObjectBuffer,0,sizeof(StartData.ObjectBuffer));
          rc = DosStartSession(&StartData,&SessID,&ProcID); MSGBOXCLEAR
          switch(rc){
             case NO_ERROR: if (!ByPass) ShowMsgExecOk(); break;
             case ERROR_FILE_NOT_FOUND: ShowMsgExecNotF(); break;
             default: ShowMsgExecErr(); break;
          }
       }
       else{
          memcpy(CmdParm,FlDis[SelFl].Nm+29,j=strlen(FlDis[SelFl].Nm+29));
          memset(CmdParm+j,' ',1);
          memcpy(CmdParm+j+1,InpLine,strlen(InpLine)+1);
          puts(CLEAR); CMDEXEC if (!ByPass) RedrawScreen();
          FlMove=1;/*MarkFileExec終了処理のためのﾌﾗｸﾞ*/
       }
    }
    if (!ByPass) QDriveSize();
 }

/**** FileCopy ***************************************************/
 void FileCopy(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ファイルをコピーします                            ",50);
    memcpy(MsgTxt[1]," File:                                            ",50);
    memset(MsgTxt[2],0,50);
    memcpy(MsgTxt[3],"コピー先を指定して下さい            (↑ｷｰでﾋｽﾄﾘｰ) ",50);
    memset(MsgTxt[4],0,50);
    memset(MsgTxt[5],0,50);
    memcpy(MsgTxt[6],"           Enter:実行         Esc:取消            ",50);
    memcpy(MsgTxt[1]+6,FlDis[SelFl].Nm+29,strlen(FlDis[SelFl].Nm+29));
    MsgTxtLen[0]=50; MsgTxtLen[1]=50; MsgTxtLen[2]=50; MsgTxtLen[3]=50;
    MsgTxtLen[4]=50; MsgTxtLen[5]=50; MsgTxtLen[6]=50; MsgTxtLen[7]=0;
    Indent=0;LineSeq=4;MSGBOXINPUTLINE
    {
       while(!KeyInfo.chChar&&!KeyInfo.chScan){FileCopy();return;}
       MSGBOXCLEAR OverWrite=RESET; FlMove=0; FirstDisp=1;ByPass=0;
       SameDirCheck(); if (rc) return;
       if (!strlen(InpLine)) {ShowMsgNameNg();return;}
       if (FlDis[SelFl].Atr&ATTR_DIR) {DirCopy=1;FileCopyDir(FlDis[SelFl].Nm+29);}
       else {DirCopy=0;FileCopyFl(FlDis[SelFl].Nm+29,FlDis[SelFl].Nm+13);}
       MSGBOXCLEAR
       if (ByPass) {ByPass=0;return;}
       FileCopyRc();
       JumpHistInsert();
    }
    QDriveSize();
 }

/**** FileCopyDir *************************************************/
 void FileCopyDir(PSZ DirNm)
 {  
    UCHAR wDirNm[124]; strcpy(wDirNm,DirNm); DirNm=wDirNm;
    /*ｺﾋﾟｰ先が同一ﾄﾞﾗｲﾌﾞならTargetPassを絶対名にて構成する*/
    if (s=strchr(InpLine,':')){
       /*1桁目の':'*/
       if (!(s-InpLine)) {ShowMsgNameNg();rc=ByPass=1;return;}
       c=toupper(InpLine[s-InpLine-1]);memset(s-1,c,1);
       /*同一ﾄﾞﾗｲﾌﾞの相対指定->現Dir名+InpLineのDir部分*/
       if (!memcmp(s-1,DriveDis,1)&&memcmp(s+1,"\\",1)) {
          if (!strlen(s+1)) {ShowMsgSameDir();rc=ByPass=1;return;}
          SetFullDirName();
          memcpy(TargetPass,FulDirNm,i=strlen(FulDirNm));
          memcpy(TargetPass+i,s+1,strlen(s+1));
       }
       else strcpy(TargetPass,InpLine);
    }
    else if (InpLine[0]!='\\'){ /*ﾄﾞﾗｲﾌﾞ指定なし*/
       SetFullDirName();
       memcpy(TargetPass,FulDirNm,i=strlen(FulDirNm));
       memcpy(TargetPass+i,InpLine,strlen(InpLine)+1);
    }
    else strcpy(TargetPass,InpLine);
    rc=DosQueryPathInfo(TargetPass,1,&PathInfo3,sizeof(FILESTATUS3));
    switch(rc){
       case NO_ERROR:
          rc=CopyDirContents(DirNm,TargetPass);return;
       case ERROR_FILE_NOT_FOUND: /*ﾄﾞﾗｲﾌﾞ名のみ->Dir名付加*/
          if (TargetPass[(i=strlen(TargetPass))-1]==':'){
             c=TargetPass[i-2];DriveNo=(c<'a'?c-64:c-96);
             memset(TargetPass+i,'\\',1);++i;
             PathLen=124;rc=DosQueryCurrentDir(DriveNo,TargetPass+i,&PathLen);
             if (!rc) rc=CopyDirContents(DirNm,TargetPass);
             return;
          }
          else break;
       case ERROR_PATH_NOT_FOUND: break;
       default: return;
    }
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"そのﾃﾞｨﾚｸﾄﾘｰは現在存在しません",30);
    memcpy(MsgTxt[1],"作成しますか                  ",30);
    memcpy(MsgTxt[2]," Dir:                         ",30);
    memcpy(MsgTxt[3],"                              ",30);
    memcpy(MsgTxt[4],"   Ｙ:yes(Enter)  Ｎ:no(Esc)  ",30);
    memcpy(MsgTxt[2]+5,InpLine,strlen(InpLine));
    MsgTxtLen[0]=30; MsgTxtLen[1]=30; MsgTxtLen[2]=30; MsgTxtLen[3]=30;
    MsgTxtLen[4]=30; MsgTxtLen[5]=0;
    MSGBOXKBDINWHILE(KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y
                   &&KeyInfo.chChar!=c_N&&KeyInfo.chChar!=c_n
                   &&KeyInfo.chChar!=ENTER);
    MSGBOXCLEAR
    if (KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y&&KeyInfo.chChar!=ENTER) {rc=ByPass=1;return;}
    rc=CreateDirFunc(TargetPass);CreateDirFuncRc(); if (rc) {rc=ByPass=1;return;}
    rc=CopyDirContents(DirNm,TargetPass);
 }

/**** FileCopyFl **************************************************/
 void FileCopyFl(PSZ FlNm,PSZ Time)
 {
    rc=DosQueryPathInfo(InpLine,1,&PathInfo3,sizeof(FILESTATUS3));
    /*ﾃﾞｨﾚｸﾄﾘｰあり*/
    switch(rc){
       case NO_ERROR:
          rc=FileCopyFunc(FlNm,Time,InpLine);return;
       case ERROR_FILE_NOT_FOUND: /*ﾄﾞﾗｲﾌﾞ名のみ->Dir名付加*/
          if (InpLine[(i=strlen(InpLine))-1]==':'){
             c=InpLine[i-2];DriveNo=(c<'a'?c-64:c-96);
             memset(InpLine+i,'\\',1);++i;
             PathLen=124;rc=DosQueryCurrentDir(DriveNo,InpLine+i,&PathLen);
             if (!rc) rc=FileCopyFunc(FlNm,Time,InpLine);
             return;
          }
          else break;
       case ERROR_PATH_NOT_FOUND: break;
       default: return;
    }
    /*ﾃﾞｨﾚｸﾄﾘｰなし*/
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"現在存在するﾃﾞｨﾚｸﾄﾘｰではありません.       ",42);
    memset(MsgTxt[1],0,42);
    memset(MsgTxt[2],0,42);
    memcpy(MsgTxt[3],"処理方法を選択して下さい.                 ",42);
    memcpy(MsgTxt[4]," Ｙ(Enter).ﾃﾞｨﾚｸﾄﾘｰを作成しﾌｧｲﾙをｺﾋﾟｰする.",42);
    memcpy(MsgTxt[5]," Ｆ.ﾌｧｲﾙ名としてｺﾋﾟｰする.                 ",42);
    memset(MsgTxt[6],0,42);
    memcpy(MsgTxt[7],"                Ｎ/Esc:取消               ",42);
    memcpy(MsgTxt[1]+1,InpLine,strlen(InpLine));
    if (FlMove) {memcpy(MsgTxt[4]+33,"移動",4);memcpy(MsgTxt[5]+16,"移動",4);}
    MsgTxtLen[0]=42; MsgTxtLen[1]=42; MsgTxtLen[2]=42; MsgTxtLen[3]=42;
    MsgTxtLen[4]=42; MsgTxtLen[5]=42; MsgTxtLen[6]=42; MsgTxtLen[7]=42; MsgTxtLen[8]=0;
    MSGBOXKBDINWHILE(KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y
                  && KeyInfo.chChar!=c_N&&KeyInfo.chChar!=c_n
                  && KeyInfo.chChar!='F'&&KeyInfo.chChar!='f'
                  && KeyInfo.chChar!=ENTER);
    MSGBOXCLEAR
    switch(KeyInfo.chChar){
       case 'Y': case 'y': case ENTER:
          rc=CreateDirFunc(InpLine);
          if (rc) {CreateDirFuncRc();rc=ByPass=1;return;}
          for (i=strlen(InpLine);i>0&&InpLine[i-1]=='\\';--i) InpLine[i-1]=0;
          MSGBOXCLEAR FileCopyFuncDisp(FlNm);
          if (FlMove&&SameDrive) FileCopyFunc(FlNm,Time,InpLine);
          else rc=DosCopy(FlNm,InpLine,OpMode=DCPY_FAILEAS);
          break;
       case 'F': case 'f':
          if (InpLine[(ix=strlen(InpLine))-1]=='\\') {ShowMsgNameNg();KeyInfo.chChar=ESC;return;}
          for (--ix;ix>0;--ix) {if (InpLine[ix-1]=='\\') {InpLine[ix-1]=0;break;}}
          if (ix) {rc=CreateDirFunc(InpLine);CreateDirFuncRc();InpLine[ix-1]='\\';if (rc) return;}
          MSGBOXCLEAR FileCopyFuncDisp(FlNm);
          if (FlMove&&SameDrive) rc=DosMove(FlNm,InpLine);
          else rc=DosCopy(FlNm,InpLine,OpMode=DCPY_FAILEAS);
          break;
       default: KeyInfo.chChar=ESC; rc=ByPass=1;
    }
 }

/**** FileCopyFunc ***********************************************/
 APIRET FileCopyFunc(PSZ FlNm,PSZ Time,PSZ DirNm)
 {
    APIRET rca;
    switch(OverWrite){
       case RESET: case NOCOPY: case TIMECOMP:
          if (!DirCopy) FileCopyFuncDisp(FlNm);
          if (FlMove&&SameDrive){
             memcpy(TargetFl,DirNm,i=strlen(DirNm));
             if (TargetFl[i-1]!='\\') {memset(TargetFl+i,'\\',1);++i;}
             memcpy(TargetFl+i,FlNm,strlen(FlNm)+1);
             rca=DosMove(FlNm,TargetFl);
          }
          else rca=DosCopy(FlNm,DirNm,OpMode=DCPY_FAILEAS);
          break;
       case OVERWRITE:
          if (!DirCopy) FileCopyFuncDisp(FlNm);
          rca=DosCopy(FlNm,DirNm,OpMode=DCPY_FAILEAS|DCPY_EXISTING);
          break;
    }
    if (rca!=ERROR_ACCESS_DENIED) return(rca);

    /*ERROR_ACCESS_DENIEDの場合*/
    /*DirNmの中に同名ﾌｧｲﾙがあるか*/
    if (FlMove&&SameDrive);else {
       memcpy(TargetFl,DirNm,i=strlen(DirNm));
       if (TargetFl[i-1]!='\\') {memset(TargetFl+i,'\\',1);++i;}
       memcpy(TargetFl+i,FlNm,strlen(FlNm)+1);
    }
    DirHandle=0x0001; FindCnt=1;
    rca=DosFindFirst(TargetFl,&DirHandle,FlFindAtr,(PVOID)&FileInfo3,
                    sizeof(FileInfo3),&FindCnt,FIL_STANDARD);
    /*DirNm(ｺﾋﾟｰ先)そのものが同名ﾌｧｲﾙか*/
    if (rca){
       DirHandle=0x0001; FindCnt=1; strcpy(TargetFl,DirNm);
       if (rca=DosFindFirst(TargetFl,&DirHandle,FlFindAtr,(PVOID)&FileInfo3,
                            sizeof(FileInfo3),&FindCnt,FIL_STANDARD));else; 
       if (!rca) FileCopyFuncOptionOv();
    }
    if (rca) return(rca);
    if (OverWrite==NOCOPY) {rca=0;return(rca);}
    if (OverWrite==RESET) FileCopyFuncOption(FlNm);
    switch(OverWrite){
       case TIMECOMP: rca=FileCopyFuncTimeComp(FlNm,Time,TargetFl); break;
       case OVERWRITE:
          if (!DirCopy) FileCopyFuncDisp(FlNm);
          if (FileInfo3.attrFile&ATTR_READONLY){
             FileCopyFuncOptionRo(FlNm,TargetFl);
             if (KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y) return(0);
          }
          if (FlMove&&SameDrive) {
             rca=DosDelete(TargetFl);
             if (!rca) rca=DosMove(FlNm,TargetFl);
          }
          else rca=DosCopy(FlNm,DirNm,OpMode=DCPY_FAILEAS|DCPY_EXISTING);
          break;
       case NOCOPY:
          if (!DirCopy) ByPass=1;
          rc=rca=0;break;
    }
    return(rca);
 }

/**** FileCopyFuncDisp ******************************************/
 void FileCopyFuncDisp(PSZ FlNm)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0],"ファイルのコピー中です",22);
    memcpy(MsgTxt[1],"                      ",22);
    memcpy(MsgTxt[1]+1,FlNm,strlen(FlNm));
    if (FlMove&&SameDrive) memcpy(MsgTxt[0]+10,"移動中です  ",12);
    MsgTxtLen[0]=22; MsgTxtLen[1]=22; MsgTxtLen[2]=0;
    if (FirstDisp) {ShowMsgBox();FirstDisp=0;}
    else if (1<BoxHigh-4) VioWrtCharStrAtt(MsgTxt[1],BoxWide-3,BoxTop+3,BoxLeft+3,BoxLineAttr,hvio);
 }

/**** FileCopyFuncOption ****************************************/
 void FileCopyFuncOption(PSZ FlNm)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"同名のﾌｧｲﾙが存在します.           ",34);
    memset(MsgTxt[1],0,34);
    memset(MsgTxt[2],0,34);
    memcpy(MsgTxt[3],"処理方法を選択して下さい.         ",34);
    memcpy(MsgTxt[4]," Ｏ.上書きする                    ",34);
    memcpy(MsgTxt[5]," Ｔ.時刻が新しいもののみ上書きする",34);
    memcpy(MsgTxt[6]," Ｃ.同名がある場合コピーしない    ",34);
    memset(MsgTxt[7],0,34);
    memcpy(MsgTxt[8],"                Ｎ/Esc:取消       ",34);
    memcpy(MsgTxt[1]+1,FlNm,strlen(FlNm));
    MsgTxtLen[0]=34; MsgTxtLen[1]=34; MsgTxtLen[2]=34; MsgTxtLen[3]=34;
    MsgTxtLen[4]=34; MsgTxtLen[5]=34; MsgTxtLen[6]=34; MsgTxtLen[7]=34; 
    MsgTxtLen[8]=34; MsgTxtLen[9]=0;
    MSGBOXKBDINWHILE(KeyInfo.chChar!='O'&&KeyInfo.chChar!='o'
                  && KeyInfo.chChar!='T'&&KeyInfo.chChar!='t'
                  && KeyInfo.chChar!='C'&&KeyInfo.chChar!='c'
                  && KeyInfo.chChar!=c_N&&KeyInfo.chChar!=c_n);
    switch(KeyInfo.chChar){
       case 'O': case 'o': OverWrite=OVERWRITE; break;
       case 'T': case 't': OverWrite=TIMECOMP; break;
       case 'C': case 'c': OverWrite=NOCOPY; break;
       case 'N': case 'n': case ESC: KeyInfo.chChar=ESC; rc=ByPass=1; break;
       default:;
    }
    ShowMsgBoxNull();
    if (/*DirCopy&&*/!ByPass) {FirstDisp=1;FileCopyFuncDisp(" ");}
 }

/**** FileCopyFuncOptionOv ***************************************/
 void FileCopyFuncOptionOv(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"その名前のﾌｧｲﾙが存在します.   ",30);
    memcpy(MsgTxt[1],"                              ",30);
    memcpy(MsgTxt[2],"                              ",30);
    memcpy(MsgTxt[3],"処理方法を選択して下さい.     ",30);
    memcpy(MsgTxt[4]," Ｏ.上書きする                ",30);
    memcpy(MsgTxt[5]," Ｔ.時刻が新しければ上書きする",30);
    memcpy(MsgTxt[6],"                              ",30);
    memcpy(MsgTxt[7],"              Ｎ/Esc:取消     ",30);
    memcpy(MsgTxt[1]+1,InpLine,strlen(InpLine));
    MsgTxtLen[0]=30; MsgTxtLen[1]=30; MsgTxtLen[2]=30; MsgTxtLen[3]=30;
    MsgTxtLen[4]=30; MsgTxtLen[5]=30; MsgTxtLen[6]=30; MsgTxtLen[7]=30; 
    MsgTxtLen[8]=0;
    MSGBOXKBDINWHILE(KeyInfo.chChar!='O'&&KeyInfo.chChar!='o'
                  && KeyInfo.chChar!='T'&&KeyInfo.chChar!='t'
                  && KeyInfo.chChar!=c_N&&KeyInfo.chChar!=c_n);
    switch(KeyInfo.chChar){
       case 'O': case 'o': OverWrite=OVERWRITE; break;
       case 'T': case 't': OverWrite=TIMECOMP; break;
       case 'N': case 'n': case ESC: KeyInfo.chChar=ESC; OverWrite=NOCOPY; rc=ByPass=1; break;
       default:;
    }
    ShowMsgBoxNull();FirstDisp=1;
 }

/**** FileCopyFuncOptionRo ***************************************/
 void FileCopyFuncOptionRo(PSZ FlNm,PSZ Target)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"あて先がﾘｰﾄﾞ･ｵﾝﾘｰのﾌｧｲﾙです",28);
    memcpy(MsgTxt[1],"上書きしますか             ",28);
    memcpy(MsgTxt[2]," File:                     ",28);
    memcpy(MsgTxt[3],"                           ",28);
    memcpy(MsgTxt[4]," Ｙ:yes(Enter)  Ｎ:no(Esc) ",28);
    memcpy(MsgTxt[2]+6,Target,strlen(Target));
    MsgTxtLen[0]=28; MsgTxtLen[1]=28; MsgTxtLen[2]=28; MsgTxtLen[3]=28;
    MsgTxtLen[4]=28; MsgTxtLen[5]=0;
    MSGBOXKBDINWHILE(KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y
                   &&KeyInfo.chChar!=c_N&&KeyInfo.chChar!=c_n
                   &&KeyInfo.chChar!=ENTER);
    ShowMsgBoxNull();
    if (KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y&&KeyInfo.chChar!=ENTER) return;
    FirstDisp=1;FileCopyFuncDisp(FlNm);
    rc=DosQueryPathInfo(Target,1,&PathInfo3,sizeof(FILESTATUS3));
    PathInfo3.attrFile&=ATTR_SYSTEM_REV;
    PathInfo3.attrFile&=ATTR_HIDDEN_REV;
    PathInfo3.attrFile&=ATTR_READONLY_REV;
    rc=DosSetPathInfo(Target,1,&PathInfo3,sizeof(FILESTATUS3),0);
 }

/**** FileCopyFuncTimeComp ***************************************/
 APIRET FileCopyFuncTimeComp(PSZ FlNm,PSZ Time,PSZ Target)
 {
    UCHAR Time1[124],Time2[124]; APIRET rca=0;
    memcpy(Time1,Time,14);memset(Time1+14,0,1);
    sprintf(Time2,"%02.2d-%02.2d-%02.2d %02.2d:%02.2d\0",
                  (FileInfo3.fdateLastWrite.year+80)%100,
                  FileInfo3.fdateLastWrite.month,
                  FileInfo3.fdateLastWrite.day,
                  FileInfo3.ftimeLastWrite.hours,
                  FileInfo3.ftimeLastWrite.minutes);
    if (0<strcmp(Time1,Time2)) {
       if (!DirCopy) FileCopyFuncDisp(FlNm);
       if (FileInfo3.attrFile&ATTR_READONLY){
          FileCopyFuncOptionRo(FlNm,Target);
          if (KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y) {rc=ByPass=1;return(0);}
       }
       FileCopyFuncDisp(FlNm);
       if (FlMove&&SameDrive) {
          rca=DosDelete(Target);
          if (!rca) rca=DosMove(FlNm,Target);
       }
       else rca=DosCopy(FlNm,Target,OpMode=DCPY_FAILEAS|DCPY_EXISTING);
    }
    /*else if (!DirCopy) rc=ByPass=1;*/
    return(rca);
 }

/**** FileCopyRc *************************************************/
 void FileCopyRc(void)
 {
    switch(rc){
       case NO_ERROR: SETPREVFILE REDRAWFILELIST
          if (KeyInfo.chChar==ESC) ShowMsgCopyStop();
          else ShowMsgCopyOk(); break;
       case ERROR_WRITE_PROTECT: ShowMsgWriteProtect(); break;
       case ERROR_INVALID_NAME: case ERROR_FILENAME_EXCED_RANGE:
          ShowMsgNameNg(); break;
       case ERROR_INVALID_DRIVE: ShowMsgDriveErr(); break;
       case ERROR_SHARING_VIOLATION: /*ShowMsgSharedErr()*/ShowMsgDeleteErr(); break;
       case ERROR_PATH_NOT_FOUND: ShowMsgPassNg(); break;
       case ERROR_DISK_FULL: ShowMsgDiskFull(); break;
       case ERROR_DRIVE_LOCKED: ShowMsgLocked(); break;
       case ERROR_CRC: ShowMsgCrcErr(); break;
       case ERROR_NOT_READY: ShowMsgDriveNotReady(); break;
       case ERROR_SECTOR_NOT_FOUND: ShowMsgSectorNotFound(); break;
       case ERROR_NOT_DOS_DISK: ShowMsgFormatErr(); break;
       default: ShowMsgErr(); break;
    }
 }

/**** FileXCopy **************************************************/
 void FileXCopy(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ファイルをコピーします（ＸＣＯＰＹ呼び出し）",44);
    memcpy(MsgTxt[1]," File:                                      ",44);
    memset(MsgTxt[2],0,44);
    memcpy(MsgTxt[3],"コピー先を指定して下さい　                  ",44);
    memcpy(MsgTxt[4],"   ﾌｧｲﾙの場合    : ﾃﾞｨﾚｸﾄﾘｰ名[+新ﾌｧｲﾙ名]    ",44);
    memcpy(MsgTxt[5],"                   または新ﾌｧｲﾙ名           ",44);
    memcpy(MsgTxt[6],"   ﾃﾞｨﾚｸﾄﾘｰの場合: ﾃﾞｨﾚｸﾄﾘｰ名               ",44);
    memset(MsgTxt[7],0,44);
    memset(MsgTxt[8],0,44);
    memcpy(MsgTxt[9],"        Enter:実行  Esc:取消                ",44);
    memcpy(MsgTxt[1]+6,FlDis[SelFl].Nm+29,strlen(FlDis[SelFl].Nm+29));
    MsgTxtLen[0]=44; MsgTxtLen[1]=44; MsgTxtLen[2]=44; MsgTxtLen[3]=44;
    MsgTxtLen[4]=44; MsgTxtLen[5]=44; MsgTxtLen[6]=44; MsgTxtLen[7]=44;
    MsgTxtLen[8]=44; MsgTxtLen[9]=44; MsgTxtLen[10]=0;
    memset(InpLine,0,sizeof(InpLine));
    Indent=0;LineSeq=7;MSGBOXINPUTLINE
    {
       memset(FulFlNm,'\0',sizeof(FulFlNm));
       memcpy(FulFlNm,"XCOPY.EXE",9);
       memcpy(CmdParm,FlDis[SelFl].Nm+29,i=j=strlen(FlDis[SelFl].Nm+29));
       if (FlDis[SelFl].Atr&ATTR_DIR){memcpy(CmdParm+i,"\\*.*",4);i+=4;}
       memset(CmdParm+i,' ',1);
       memcpy(CmdParm+(++i),InpLine,InpLineLen);i+=InpLineLen;
       if (FlDis[SelFl].Atr&ATTR_DIR){
          if (CmdParm[i-1]!='\\') {memcpy(CmdParm+i,"\\",1);++i;}
          memcpy(CmdParm+i,FlDis[SelFl].Nm+29,j);i+=j;
          memcpy(CmdParm+i,"\\*.* /S /E /H /T /R",19);i+=19;
       }
       memset(CmdParm+i,'\0',1);
       StartData.PgmTitle   = "ファイルのコピー";
       StartData.PgmName    = FulFlNm;
       StartData.PgmInputs  = CmdParm;
       StartData.PgmControl = SSF_CONTROL_VISIBLE|SSF_CONTROL_NOAUTOCLOSE;
       memset(StartData.ObjectBuffer,0,sizeof(StartData.ObjectBuffer));
       rc = DosStartSession(&StartData, &SessID, &ProcID); MSGBOXCLEAR
    }
 }

/**** FileDelete ************************************************/
 void FileDelete(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ファイルを削除します     ",25);
    memcpy(MsgTxt[1]," File:                   ",25);
    memcpy(MsgTxt[2],"                         ",25);
    memcpy(MsgTxt[3],"Ｙ:yes(Enter)  Ｎ:no(Esc)",25);
    memcpy(MsgTxt[1]+6,FlDis[SelFl].Nm+29,strlen(FlDis[SelFl].Nm+29));
    MsgTxtLen[0]=25; MsgTxtLen[1]=25; MsgTxtLen[2]=25; MsgTxtLen[3]=25;
    MsgTxtLen[4]=0;
    MSGBOXKBDINWHILE(KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y
                   &&KeyInfo.chChar!=c_N&&KeyInfo.chChar!=c_n
                   &&KeyInfo.chChar!=ENTER);
    MSGBOXCLEAR FlMove=0;ByPass=0;
    if (KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y&&KeyInfo.chChar!=ENTER) return;
    DirDel=0; FileDeleteFunc(FlDis[SelFl].Nm+29,FlDis[SelFl].Atr);
    if (rc) {FileDeleteRc();return;}
    QDriveSize();
    ReDrawAfterDelete();
    /*if (rc&&DirDel) ShowMsgBoxNull();*/
 }

/**** FileDeleteFunc ********************************************/
 void FileDeleteFunc(PSZ FlNm,BYTE FlAtr)
 {
    FirstDisp=1;
    if (FlAtr&ATTR_SYSTEM||FlAtr&ATTR_HIDDEN||FlAtr&ATTR_READONLY){
       BoxLineAttr=GrayYellow;
       memcpy(MsgTxt[0],"ｼｽﾃﾑ/隠し/ﾘｰﾄﾞ･ｵﾝﾘｰのﾌｧｲﾙです",30);
       memcpy(MsgTxt[1],"削除しますか                 ",30);
       memcpy(MsgTxt[2]," File:                       ",30);
       memcpy(MsgTxt[3],"                             ",30);
       memcpy(MsgTxt[4],"  Ｙ:yes(Enter)  Ｎ:no(Esc)  ",30);
       memcpy(MsgTxt[2]+6,FlNm,strlen(FlNm));
       MsgTxtLen[0]=30; MsgTxtLen[1]=30; MsgTxtLen[2]=30; MsgTxtLen[3]=30;
       MsgTxtLen[4]=30; MsgTxtLen[5]=0;
       MSGBOXKBDINWHILE(KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y
                      &&KeyInfo.chChar!=c_N&&KeyInfo.chChar!=c_n
                      &&KeyInfo.chChar!=ENTER);
       ShowMsgBoxNull();
       if (KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y&&KeyInfo.chChar!=ENTER) {rc=1;return;}
       rc=DosQueryPathInfo(FlNm,1,&PathInfo3,sizeof(FILESTATUS3));
       PathInfo3.attrFile&=ATTR_SYSTEM_REV;
       PathInfo3.attrFile&=ATTR_HIDDEN_REV;
       PathInfo3.attrFile&=ATTR_READONLY_REV;
       rc=DosSetPathInfo(FlNm,1,&PathInfo3,sizeof(FILESTATUS3),0);
    }
    if (!(FlAtr&ATTR_DIR)) {
       DirDel=0; FileDeleteFuncDisp(FlNm);
       rc=DosDelete(FlNm);
       if (rc) strcpy(InpLine,FlNm);
    }
    else{
       if (!FlMove){
          BoxLineAttr=GrayYellow;
          memcpy(MsgTxt[0],"ディレクトリーです       ",25);
          memcpy(MsgTxt[1],"削除しますか             ",25);
          memcpy(MsgTxt[2]," Dir:                    ",25);
          memcpy(MsgTxt[3],"                         ",25);
          memcpy(MsgTxt[4],"Ｙ:yes(Enter)  Ｎ:no(Esc)",25);
          memcpy(MsgTxt[2]+5,FlNm,strlen(FlNm));
          MsgTxtLen[0]=25; MsgTxtLen[1]=25; MsgTxtLen[2]=25; MsgTxtLen[3]=25;
          MsgTxtLen[4]=25; MsgTxtLen[5]=0;
          MSGBOXKBDINWHILE(KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y
                         &&KeyInfo.chChar!=c_N&&KeyInfo.chChar!=c_n
                         &&KeyInfo.chChar!=ENTER);
          ShowMsgBoxNull();
          if (KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y&&KeyInfo.chChar!=ENTER) return;
       }
       DirDel=1; FileDeleteFuncDisp(" ");
       rc=DeleteDirContents(FlNm);
       if (!rc) {
          FileDeleteFuncDisp(FlNm);
          rc=DosDeleteDir(FlNm);
       }
    }
 }

/**** FileDeleteFuncDisp ****************************************/
 void FileDeleteFuncDisp(PSZ FlNm)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0],"ファイルの削除中です",20);
    memcpy(MsgTxt[1],"                    ",20);
    memcpy(MsgTxt[1]+1,FlNm,strlen(FlNm));
    MsgTxtLen[0]=20; MsgTxtLen[1]=20; MsgTxtLen[2]=0;
    if (FirstDisp) {ShowMsgBox();FirstDisp=0;}
    else if (1<BoxHigh-4) VioWrtCharStrAtt(MsgTxt[1],BoxWide-3,BoxTop+3,BoxLeft+3,BoxLineAttr,hvio);
 }

/**** FileDeleteRc **********************************************/
 void FileDeleteRc(void)
 {
    if (KeyInfo.chChar==ESC) ShowMsgDeleteStop();
    else switch(rc){
       case NO_ERROR: break;
       case ERROR_SHARING_VIOLATION: /*ShowMsgSharedErr()*/ShowMsgDeleteErr(); break;
       case ERROR_CURRENT_DIRECTORY: ShowMsgDeleteErr(); break;
       case ERROR_WRITE_PROTECT: ShowMsgWriteProtect(); break;
       case ERROR_ACCESS_DENIED: ShowMsgDeleteDeny(); break;
       default: ShowMsgErr();
    }
 }

/**** FileEdit **************************************************/
 void FileEdit(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ファイルの編集をします              ",36);
    memcpy(MsgTxt[1],"  □ｴﾃﾞｨﾀｰ指定:                     ",36);
    memcpy(MsgTxt[2],"  □別ｾｯｼｮﾝを生成する               ",36);
    memset(MsgTxt[3],0,36);
    memcpy(MsgTxt[4],"編集するファイル名を指定して下さい  ",36);
    memset(MsgTxt[5],0,36);
    memset(MsgTxt[6],0,36);
    memcpy(MsgTxt[7],"    Enter:実行  Esc:取消            ",36);
    MsgTxtLen[0]=36; MsgTxtLen[1]=36; MsgTxtLen[2]=36; MsgTxtLen[3]=36;
    MsgTxtLen[4]=36; MsgTxtLen[5]=36; MsgTxtLen[6]=36; MsgTxtLen[7]=36;
    MsgTxtLen[8]=0;
    memcpy(MsgTxt[1]+15,EditorName,strlen(EditorName));
    if (EditorNameSet) memcpy(MsgTxt[1]+2,C_BOX1,2);
    else memcpy(MsgTxt[2]+2,C_BOX0,2);
    if (EditSession) memcpy(MsgTxt[2]+2,C_BOX1,2);
    else memcpy(MsgTxt[2]+2,C_BOX0,2);
    if (memcmp(FlDis[SelFl].Nm+29,"..",2)) strcpy(InpLine,FlDis[SelFl].Nm+29);
    Indent=0;LineSeq=5;MSGBOXINPUTLINE
    {
       MSGBOXCLEAR
       if (EditSession){
          memset(FulFlNm,'\0',sizeof(FulFlNm));
          memcpy(FulFlNm,EditorName,strlen(EditorName));
          StartData.PgmTitle   = FlDis[SelFl].Nm+29;
          StartData.PgmTitle   = "ファイルの編集（別プロセス）";
          StartData.PgmName    = FulFlNm;
          StartData.PgmInputs  = InpLine;
          StartData.PgmControl = SSF_CONTROL_VISIBLE;
          memset(StartData.ObjectBuffer,0,sizeof(StartData.ObjectBuffer));
          rc = DosStartSession(&StartData, &SessID, &ProcID);
       }
       else{
          memcpy(CmdParm,EditorName,i=strlen(EditorName));
          memset(CmdParm+i,' ',1);
          memcpy(CmdParm+(++i),InpLine,strlen(InpLine)+1);
          VioWrtCharStrAtt(FlDis[SelFl].Nm,ColMax,Row,0,FlDis[SelFl].DisAtr,hvio);
          CMDEXEC
          RedrawScreen();
       }
       QDriveSize();
    }
 }


/**** FileFind **************************************************/
 void FileFind(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ファイルを探索します             ",33);
    memcpy(MsgTxt[1],"                                 ",33);
    memcpy(MsgTxt[2],"探すファイル名を指定して下さい   ",33);
    memcpy(MsgTxt[3],"                                 ",33);
    memcpy(MsgTxt[4],"                                 ",33);
    memcpy(MsgTxt[5],"     Enter:実行   Esc:取消       ",33);
    MsgTxtLen[0]=33; MsgTxtLen[1]=33; MsgTxtLen[2]=33; MsgTxtLen[3]=33;
    MsgTxtLen[4]=33; MsgTxtLen[5]=33; MsgTxtLen[6]=0;
    memset(InpLine,0,sizeof(InpLine));
    Indent=0;LineSeq=3;MSGBOXINPUTLINE
    {
       MSGBOXCLEAR FirstDisp=1; AssocFind=0;
       SetFullDirName(); strcpy(PrevDir,FulDirNm); memset(PrevDir+(strlen(PrevDir)-1),0,1);
       SelFlSv=SelFl; FileFindDir("\\"); FirstDisp=1;
       if (!AssocFind) SelFl=SelFlSv;
       if (KeyInfo.chChar==ESC){
          DosSetCurrentDir(PrevDir); QDir(); REDRAWFILELIST
          ShowMsgFindStop(); return;
       }
       if (!AssocFind){
          DosSetCurrentDir(PrevDir); QDir(); REDRAWFILELIST
          ShowMsgNotFound();
       }
    }
 }

/**** FileFindDir *********************************************/
 void FileFindDir(PSZ DirNm)
 {
    int ia;
    DosSetCurrentDir(DirNm);
    PathLen=124;DosQueryCurrentDir(0,PathDis+1,&PathLen);SetFullDirName();
    FileFindDisp(FulDirNm);
    strcpy(FlMask,InpLine); QFile();
    if (FlCnt) for (ia=0,k=1;ia<FlCnt&&KeyInfo.chChar!=ESC&&!AssocFind;ia++){
       if (!(FlDis[ia].Atr&ATTR_DIR)){
          SelFl=ia;SetFullFileName(); FileFindMatch(FulFlNm);k=0;
       }
       if (KeyInfo.chChar==' '&&ia==FlCnt-1) {ShowMsgBoxNull();FirstDisp=1;}
       if (AssocFind) return;
    }
    strcpy(FlMask,"*.*"); QFile();
    for (ia=1;ia<FlCnt&&KeyInfo.chChar!=ESC&&!AssocFind;++ia){
       KbdCharIn(&KeyInfo,IO_NOWAIT,0);
       if (FlDis[ia].Atr&ATTR_DIR) FileFindDir(FlDis[ia].Nm+29);
    }
    if (!AssocFind) {DosSetCurrentDir("..");QFile();}
 }

/**** FileFindMatch *********************************************/
 void FileFindMatch(PSZ FlNm)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ファイルが見つかりました                    ",44);
    memcpy(MsgTxt[1],"                                            ",44);
    memcpy(MsgTxt[2],"                                            ",44);
    memcpy(MsgTxt[3],"Ｙ(Enter) ：そのディレクトリーに移動する    ",44);
    memcpy(MsgTxt[4],"Ｎ(Space) ：次を探す                        ",44);
    memcpy(MsgTxt[5],"Ｃ(Esc)   ：探索を中止する                  ",44);
    memcpy(MsgTxt[1]+1,FulFlNm,strlen(FulFlNm));
    MsgTxtLen[0]=44; MsgTxtLen[1]=44; MsgTxtLen[2]=44; MsgTxtLen[3]=44;
    MsgTxtLen[4]=44; MsgTxtLen[5]=44; MsgTxtLen[6]=0;
    if (k) ShowMsgBox();
    else if (1<BoxHigh-4) VioWrtCharStrAtt(MsgTxt[1],BoxWide-6,BoxTop+3,BoxLeft+3,BoxLineAttr,hvio);
    KBDINWHILE(KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y
              &&KeyInfo.chChar!=c_N&&KeyInfo.chChar!=c_n
              &&KeyInfo.chChar!='C'&&KeyInfo.chChar!='c'
              &&KeyInfo.chChar!=' '
              &&KeyInfo.chChar!=ENTER
              &&KeyInfo.chChar!=ESC);
    switch(KeyInfo.chChar){
       case ENTER: case 'Y': case 'y':
          KeyInfo.chChar=c_Y; AssocFind=1;
          strcpy(PrevFl,FlDis[SelFl].Nm+29);
          strcpy(FlMask,"*.*");
          QDir(); QFile(); PrevFileSearch(); REDRAWFILELIST
          break;
       case 'N': case 'n': KeyInfo.chChar=' '; break;
       case 'C': case 'c': KeyInfo.chChar=ESC; break;
    }
 }

/**** FileFindDisp **********************************************/
 void FileFindDisp(PSZ DirNm)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0],"ファイルの探索中です：                      ",44);
    memcpy(MsgTxt[1],"                                            ",44);
    memcpy(MsgTxt[0]+22,InpLine,strlen(InpLine));
    memcpy(MsgTxt[1]+1,DirNm,strlen(DirNm));
    MsgTxtLen[0]=44; MsgTxtLen[1]=44; MsgTxtLen[2]=0;
    if (FirstDisp) {ShowMsgBox();FirstDisp=0;}
    else if (1<BoxHigh-4) VioWrtCharStrAtt(MsgTxt[1],BoxWide-6,BoxTop+3,BoxLeft+3,BoxLineAttr,hvio);
 }

/**** FileMark **************************************************/
 void FileMark(void)
 {
    if (memcmp(FlDis[SelFl].Nm+6,"<Dir>",5))
       sscanf(FlDis[SelFl].Nm," %10d ",&FileInfo3.cbFile);
    else FileInfo3.cbFile=0;
    if (memcmp(FlDis[SelFl].Nm+27,"★",2)) {
       memcpy(FlDis[SelFl].Nm+27,"★",2);
       ++MarkCnt; MarkSize+=FileInfo3.cbFile; FlMark[SelFl]=1;
    }
    else {
       memcpy(FlDis[SelFl].Nm+27,"  ",2);
       --MarkCnt; MarkSize-=FileInfo3.cbFile; FlMark[SelFl]=0;
    }
    memset(MarkCntDis+2,0,sizeof(MarkCntDis)-2);
    if (MarkCnt) sprintf(MarkCntDis,"★%d(%uK)",MarkCnt,MarkSize/1000);
    else sprintf(MarkCntDis,"☆%d(%uK)",MarkCnt,MarkSize/1000);
    VioWrtCharStrAtt(MarkCntDis,MarkCntDisLen,2,20,BlueBright,hvio);
 }

/**** FileMarkAll ***********************************************/
 void FileMarkAll(void)
 {
    if (MarkCnt){
       MarkCnt=0; MarkSize=0;
       for(i=0;i<FlCnt;++i) {memcpy(FlDis[i].Nm+27,"  ",2);FlMark[i]=0;}
    }
    else {
       MarkCnt=0; MarkSize=0;
       for(i=0;i<FlCnt;++i){
          if (memcmp(FlDis[i].Nm+29,"..",2)){
             memcpy(FlDis[i].Nm+27,"★",2);
             if (memcmp(FlDis[i].Nm+6,"<Dir>",5)) sscanf(FlDis[i].Nm," %10d ",&FileInfo3.cbFile);
             else FileInfo3.cbFile=0;
             ++MarkCnt; MarkSize+=FileInfo3.cbFile; FlMark[i]=1;
          }
       }
    }
    memset(MarkCntDis+2,0,sizeof(MarkCntDis)-2);
    if (MarkCnt) sprintf(MarkCntDis,"★%d(%uK)",MarkCnt,MarkSize/1000);
    else sprintf(MarkCntDis,"☆%d(%uK)",MarkCnt,MarkSize/1000);
    MSGBOXCLEAR
 }

/**** FileMaskDisp***********************************************/
 void FileMaskDisp(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ファイル・マスク(ﾜｲﾙﾄﾞ･ｶｰﾄﾞ)文字を変更します",44);
    memcpy(MsgTxt[1],"                                            ",44);
    memcpy(MsgTxt[2],"                                            ",44);
    memcpy(MsgTxt[3],"                                            ",44);
    memcpy(MsgTxt[4],"        Enter:実行  Esc:取消                ",44);
    MsgTxtLen[0]=44; MsgTxtLen[1]=44; MsgTxtLen[2]=44; MsgTxtLen[3]=44;
    MsgTxtLen[4]=44; MsgTxtLen[5]=0;
    memset(InpLine,0,sizeof(InpLine));
    strcpy(InpLine,FlMask);
    Indent=0;LineSeq=2;MSGBOXINPUTLINE
    {
       if (!strlen(InpLine)) {MSGBOXCLEAR ShowMsgNameNg();return;}
       strcpy(FlMask,InpLine);
       QFile(); SelFl=StartFl=0; ShowType=1; ShowFileList();
       VioWrtNChar(" ",ColMax-70,2,70,hvio);
       VioWrtCharStrAtt(FlMask,strlen(FlMask),2,70,WallAttr,hvio);
    }
 }

/**** FileMove **************************************************/
 void FileMove(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ファイルを移動します                              ",50);
    memcpy(MsgTxt[1]," File:                                            ",50);
    memset(MsgTxt[2],0,50);
    memcpy(MsgTxt[3],"移動先を指定して下さい　            (↑ｷｰでﾋｽﾄﾘｰ) ",50);
    memset(MsgTxt[4],0,50);
    memset(MsgTxt[5],0,50);
    memcpy(MsgTxt[6],"            Enter:実行       Esc:取消             ",50);
    memcpy(MsgTxt[1]+6,FlDis[SelFl].Nm+29,strlen(FlDis[SelFl].Nm+29));
    MsgTxtLen[0]=50; MsgTxtLen[1]=50; MsgTxtLen[2]=50; MsgTxtLen[3]=50;
    MsgTxtLen[4]=50; MsgTxtLen[5]=50; MsgTxtLen[6]=50; MsgTxtLen[7]=0;
    Indent=0;LineSeq=4;MSGBOXINPUTLINE
    {
       while(!KeyInfo.chChar&&!KeyInfo.chScan){FileMove();return;}
       MSGBOXCLEAR OverWrite=RESET; FirstDisp=1;ByPass=0;
       if (!strlen(InpLine)) {ShowMsgNameNg();return;}
       SameDirCheck(); if (rc) return;
       FlMove=1;
       SameDriveCheck();
       if (FlDis[SelFl].Atr&ATTR_DIR) {DirCopy=1;FileCopyDir(FlDis[SelFl].Nm+29);}
       else {DirCopy=0;FileCopyFl(FlDis[SelFl].Nm+29,FlDis[SelFl].Nm+13);}
       if (rc) {if (!ByPass) {MSGBOXCLEAR FileCopyRc();} return;}
       if (KeyInfo.chChar==ESC||(SameDrive&&(!DirCopy)));else{
          FileDeleteFunc(FlDis[SelFl].Nm+29,FlDis[SelFl].Atr);
          if (rc!=ERROR_FILE_NOT_FOUND&&rc) {FileDeleteRc();return;}
          QDriveSize();
       }
       ReDrawAfterDelete();QDriveSize();
       if (KeyInfo.chChar==ESC) ShowMsgMoveStop();
       if (ByPass) {ByPass=0;return;}
       FlMove=0;
       JumpHistInsert();
    }
 }

/**** FileName **************************************************/
 void FileName(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ファイル／ディレクトリーを改名します        ",44);
    memcpy(MsgTxt[1],"                                            ",44);
    memcpy(MsgTxt[2],"新しい名前を指定して下さい                  ",44);
    memcpy(MsgTxt[3],"                                            ",44);
    memcpy(MsgTxt[4],"                                            ",44);
    memcpy(MsgTxt[5],"        Enter:実行  Esc:取消                ",44);
    MsgTxtLen[0]=44; MsgTxtLen[1]=44; MsgTxtLen[2]=44; MsgTxtLen[3]=44;
    MsgTxtLen[4]=44; MsgTxtLen[5]=44; MsgTxtLen[6]=0;
    memset(InpLine,0,sizeof(InpLine));
    strcpy(InpLine,FlDis[SelFl].Nm+29);
    Indent=0;LineSeq=3;MSGBOXINPUTLINE
    {
       MSGBOXCLEAR
       if (!strlen(InpLine)) {ShowMsgNameNg();return;}
       rc=DosMove(FlDis[SelFl].Nm+29,InpLine);MSGBOXCLEAR
       if (rc==NO_ERROR) {REDRAWFILELIST}
       else ShowMsgNameErr();
    }
 }

/*** FileNameComp ***********************************************/
 int FileNameComp(const void *PFlDis1, const void *PFlDis2)
 {
    struct _FlDis *P1=(struct _FlDis *)PFlDis1;
    struct _FlDis *P2=(struct _FlDis *)PFlDis2;
    UCHAR n1[FILE_DISPLEN+1],n2[FILE_DISPLEN+1];

    memset(n1,0,sizeof(n1));
    if (!memcmp(P1->Nm+29,"..",2)) memset(n1,1,1);
    else if (P1->Atr&ATTR_SYSTEM) memset(n1,2,1);
    else if (P1->Atr&ATTR_DIR) memset(n1,3,1);
    else memset(n1,4,1);

    memset(n2,0,sizeof(n2));
    if (!memcmp(P2->Nm+29,"..",2)) memset(n2,1,1);
    else if (P2->Atr&ATTR_SYSTEM) memset(n2,2,1);
    else if (P2->Atr&ATTR_DIR) memset(n2,3,1);
    else memset(n2,4,1);

    strcpy(n1+1,P1->Nm+29);
    strcpy(n2+1,P2->Nm+29);
    return(strcmp(n1,n2));
 }

/*** FileNameCompOption *****************************************/
 int FileNameCompOption(const void *PFlDis1, const void *PFlDis2)
 {
    struct _FlDis *P1=(struct _FlDis *)PFlDis1;
    struct _FlDis *P2=(struct _FlDis *)PFlDis2;
    UCHAR n1[FILE_DISPLEN+1],n2[FILE_DISPLEN+1];

    switch(KeyInfo.chChar){
       case 'N': case 'n': 
          memset(n1,0,sizeof(n1));
          if (!memcmp(P1->Nm+29,"..",2)) memset(n1,1,1);
          else if (P1->Atr&ATTR_SYSTEM) memset(n1,2,1);
          else if (P1->Atr&ATTR_DIR) memset(n1,3,1);
          else memset(n1,4,1);
          memset(n2,0,sizeof(n2));
          if (!memcmp(P2->Nm+29,"..",2)) memset(n2,1,1);
          else if (P2->Atr&ATTR_SYSTEM) memset(n2,2,1);
          else if (P2->Atr&ATTR_DIR) memset(n2,3,1);
          else memset(n2,4,1);
          strcpy(n1+1,P1->Nm+29);
          strcpy(n2+1,P2->Nm+29);
          return(strcmp(n1,n2));
          break;
       case 'T': case 't': 
          memset(n1,0,sizeof(n1));
          if (!memcmp(P1->Nm+29,"..",2)) memset(n1,4,1);
          else if (P1->Atr&ATTR_SYSTEM) memset(n1,3,1);
          else if (P1->Atr&ATTR_DIR) memset(n1,2,1);
          else memset(n1,1,1);
          memset(n2,0,sizeof(n2));
          if (!memcmp(P2->Nm+29,"..",2)) memset(n2,4,1);
          else if (P2->Atr&ATTR_SYSTEM) memset(n2,3,1);
          else if (P2->Atr&ATTR_DIR) memset(n2,2,1);
          else memset(n2,1,1);
          strcpy(n1+1,P1->Nm+13);
          strcpy(n2+1,P2->Nm+13);
          return(strcmp(n2,n1));
          break;
       case 'S': case 's': 
          memset(n1,0,sizeof(n1));
          if (!memcmp(P1->Nm+29,"..",2)) memset(n1,4,1);
          else if (P1->Atr&ATTR_SYSTEM) memset(n1,3,1);
          else if (P1->Atr&ATTR_DIR) memset(n1,2,1);
          else memset(n1,1,1);
          memset(n2,0,sizeof(n2));
          if (!memcmp(P2->Nm+29,"..",2)) memset(n2,4,1);
          else if (P2->Atr&ATTR_SYSTEM) memset(n2,3,1);
          else if (P2->Atr&ATTR_DIR) memset(n2,2,1);
          else memset(n2,1,1);
          strcpy(n1+1,P1->Nm);
          strcpy(n2+1,P2->Nm);
          return(strcmp(n2,n1));
          break;
    }
 }

/**** FilePathSearch ********************************************/
 APIRET FilePathSearch(PSZ FlNm)
 {
    /*DosScanEnv("PATH",&StartData.ObjectBuffer);*/
    rc=DosSearchPath(SEARCH_CUR_DIRECTORY|SEARCH_ENVIRONMENT,
                     "PATH",FlNm,FulFlNm,sizeof(ObjBuf));
 }

/**** FileSort **************************************************/
 void FileSort(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ファイル一覧の  ートをします",28);
    memcpy(MsgTxt[0]+14,So,2);
    memcpy(MsgTxt[1]," ｿｰﾄ方法を選択して下さい    ",28);
    memset(MsgTxt[2],0,28);
    memcpy(MsgTxt[3]," Ｎ.ファイル名              ",28);
    memcpy(MsgTxt[4]," Ｔ.時刻   (新しい順)       ",28);
    memcpy(MsgTxt[5]," Ｓ.サイズ (大きい順)       ",28);
    memset(MsgTxt[6],0,28);
    memcpy(MsgTxt[7],"             Esc:取消       ",28);
    MsgTxtLen[0]=28; MsgTxtLen[1]=28; MsgTxtLen[2]=28; MsgTxtLen[3]=28;
    MsgTxtLen[4]=28; MsgTxtLen[5]=28; MsgTxtLen[6]=28; MsgTxtLen[7]=28;
    MsgTxtLen[8]=0;
    MSGBOXKBDINWHILE(KeyInfo.chChar!=c_N&&KeyInfo.chChar!=c_n
                  && KeyInfo.chChar!='T'&&KeyInfo.chChar!='t'
                  && KeyInfo.chChar!='S'&&KeyInfo.chChar!='s');
    if (KeyInfo.chChar==ESC) {MSGBOXCLEAR}
    else {qsort(FlDis,FlCnt,sizeof(struct _FlDis),FileNameCompOption);SHOWTOP}
 }

/**** FuncEvent *************************************************/
 void FuncEvent(void)
 {
    switch(KeyInfo.chScan){
       case ARROW_UP: case ARROW_LEFT:
          if (Row>4){
             VioWrtCharStrAtt(FlDis[SelFl].Nm,ColMax,Row,0,FlDis[SelFl].DisAtr,hvio);
             VioWrtCharStrAtt(FlDis[--SelFl].Nm,ColMax,SaveRow=--Row,0,FlDis[SelFl].DisAtr+1,hvio);
             VioSetCurPos(Row,0,hvio);
          }
          else if(PageNo>1) {ShowType=2;--PageNo;StartFl-=(RowMax-5);ShowFileList();}
          break;
       case ARROW_DOWN: case ARROW_RIGHT: case SPACE:
          if (KeyInfo.chScan==SPACE&&memcmp(FlDis[SelFl].Nm+29,"..",2)) FileMark();
          if (Row<RowMax-2 && SelFl<FlCnt-1){
             VioWrtCharStrAtt(FlDis[SelFl].Nm,ColMax,Row,0,FlDis[SelFl].DisAtr,hvio);
             VioWrtCharStrAtt(FlDis[++SelFl].Nm,ColMax,SaveRow=++Row,0,FlDis[SelFl].DisAtr+1,hvio);
             VioSetCurPos(Row,0,hvio);
          }
          else if (FlCnt-StartFl>RowMax-5){
             ++PageNo;SelFl=StartFl+=(RowMax-5);
             ShowType=1;ShowFileList();
          }
          else if (SelFl==FlCnt-1) VioWrtCharStrAtt(FlDis[SelFl].Nm,ColMax,Row,0,FlDis[SelFl].DisAtr+1,hvio);
          break;
       case PAGE_UP:
          if (PageNo>1) {ShowType=1;--PageNo;StartFl-=(RowMax-5);ShowFileList();}
          break;
       case PAGE_DOWN:
          if (FlCnt-StartFl>RowMax-5){
             ++PageNo;SelFl=StartFl+=(RowMax-5);
             ShowType=1;ShowFileList();
          }
          break;
       case PLUS:
          VioWrtCharStrAtt(FlDis[SelFl].Nm,ColMax,Row,0,FlDis[SelFl].DisAtr,hvio);
          if (FlCnt-StartFl<RowMax-5){
             i=FlCnt-StartFl+3-Row;
             VioWrtCharStrAtt(FlDis[(SelFl+=i)].Nm,ColMax,SaveRow=Row+=i,0,FlDis[SelFl].DisAtr+1,hvio);
             VioSetCurPos(Row,0,hvio);
          }
          else{
             VioWrtCharStrAtt(FlDis[(SelFl+=(RowMax-2-Row))].Nm,ColMax,RowMax-2,0,FlDis[SelFl].DisAtr+1,hvio);
             VioSetCurPos(SaveRow=Row=(RowMax-2),0,hvio);
          }
          break;
       case MINUS:
          VioWrtCharStrAtt(FlDis[SelFl].Nm,ColMax,Row,0,FlDis[SelFl].DisAtr,hvio);
          VioWrtCharStrAtt(FlDis[(SelFl=StartFl)].Nm,ColMax,4,0,FlDis[SelFl].DisAtr+1,hvio);
          VioSetCurPos(SaveRow=Row=4,0,hvio);
          break;
       case HOME: SHOWTOP break;
       case END: ShowBottom(); break;
       case INSERT: FileMarkAll(); break;
       case DELETE: Serch1Char(); break;
       case PF1: ShowHelp1(); break;
       case PF2: ChangeSetup(); break;
       case PF3: QuitFilestar(); break;
       case PF4: MacroDisp(); break;
       case PF12: DisplayTheatre(); break;
       default:;
    }
 }

/**** GetMode ***************************************************/
 void GetMode(void)
 {
    VioModeInfo.cb = sizeof(VioModeInfo);
    VioGetMode(&VioModeInfo,hvio );
    RowMax=VioModeInfo.row;
    ColMax=VioModeInfo.col;
    memset (Title,0,sizeof(Title));
    if (ColMax>74) memcpy(Title," ★☆☆☆☆★ＦｉｌｅＳｔａｒ★☆☆☆☆★  Version2.33 By Ｇeorge,1996.09",74);
    else if(ColMax>66) memcpy(Title," ★☆☆★ＦｉｌｅＳｔａｒ★☆☆★  Version2.33 By Ｇeorge,1996.09",66);
    else if(ColMax>53) memcpy(Title," ★ＦｉｌｅＳｔａｒ★ Version2.33 By Ｇeorge,1996.09",53);
    else if(ColMax>44) memcpy(Title," ★ＦｉｌｅＳｔａｒ★ Version2.33 By Ｇeorge",44);
    else if(ColMax>33) memcpy(Title," ★ＦｉｌｅＳｔａｒ★ Version2.33",33);
    else memcpy(Title," ★ＦｉｌｅＳｔａｒ★",21);
 }

/**** GetOriginDir **********************************************/
 void GetOriginDir(void)
 {
    DosQueryCurrentDisk(&DriveNo,&DriveMap);
    DriveDis[0]=DriveChar[DriveNo-1];
    PathLen=124;DosQueryCurrentDir(0,PathDis+1,&PathLen);
    memcpy(OriginDir,DriveDis,2);
    strcpy(OriginDir+2,PathDis);
    memcpy(FlstrDirFl,OriginDir,i=strlen(OriginDir));
    if (FlstrDirFl[i-1]!='\\') {memset(FlstrDirFl+i,'\\',1);i++;}
    strcpy(FlstrDirFl+i,"FILESTAR.DIR");
 }

/**** GetParm ***************************************************/
 void GetParm(void)
 {
    StartFl=FlMove=0;
    if (FulDirNm[0]){
       c=FulDirNm[0];
       DriveNo=(c<'a'?c-64:c-96);
       StartupDirErr=DosSetDefaultDisk(DriveNo);
       if(!StartupDirErr) StartupDirErr=DosSetCurrentDir(FulDirNm+2);
       if(!StartupDirErr) StartFl=1;
       if (!StartFl) FlMove=1;
    }
 }

/**** GoStartupDir ***********************************************/
 void GoStartupDir(void)
 {
    c=StartupDir[0];
    DriveNo=(c<'a'?c-64:c-96);
    StartupDirErr=DosSetDefaultDisk(DriveNo);
    if(!StartupDirErr) StartupDirErr=DosSetCurrentDir(StartupDir+2);
 }

/**** IniFileRead ************************************************/
 void IniFileRead(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"FILESTAR.INIﾌｧｲﾙの読み込みをします",34);
    memcpy(MsgTxt[1],"                                  ",34);
    memcpy(MsgTxt[2],"     Enter:実行    Esc:取消       ",34);
    MsgTxtLen[0]=34; MsgTxtLen[1]=34; MsgTxtLen[2]=34; MsgTxtLen[3]=0;
    MSGBOXKBDINWHILECR
    {
       FirstDisp=0;/*GoStartupDir,ｻｲｽﾞ変更を行わせない*/
       InitCustomize();
    }
 }

/**** InitCustomize **********************************************/
 void InitCustomize(void)
 {
    AssocCnt=0;
    strcpy(IniFileIn,OriginDir);strcat(IniFileIn,"\\FILESTAR.INI");
    Fl=fopen(IniFileIn,"r"); if (Fl==NULL) return;
    IniFileBuf=fgets(IniFileIn,sizeof(IniFileIn),Fl);
    while(IniFileBuf){
       if (!memcmp(IniFileIn,"<General>",9)) IniSection=INI_GENERAL;
       else if (!memcmp(IniFileIn,"<Editor>",8)) IniSection=INI_EDITOR;
       else if (!memcmp(IniFileIn,"<Extension>",11)) IniSection=INI_EXTENTION;
       else if (!memcmp(IniFileIn,"<Macro>",7)) IniSection=INI_MACRO;
       switch(IniSection){
          case INI_GENERAL: SetupGeneral(); break;
          case INI_EDITOR: SetupEditor(); break;
          case INI_EXTENTION: SetupExtention(); break;
          case INI_MACRO:
             memcpy(Footer+38,C_BOX1,2);
             MacroSetup(); break;
          default: break;
       }
       IniFileBuf=fgets(IniFileIn,sizeof(IniFileIn),Fl);
    }
    fclose(Fl);
    memcpy(Footer+1,C_BOX1,2);
 }

/**** InitStartData **********************************************/
 void InitStartData(void)
 {
    StartData.Length      = sizeof(STARTDATA);
    StartData.Related     = SSF_RELATED_INDEPENDENT;
    StartData.FgBg        = SSF_FGBG_FORE;
    StartData.TraceOpt    = SSF_TRACEOPT_NONE;
    StartData.TermQ       = 0;
    StartData.Environment = 0;
    StartData.InheritOpt  = SSF_INHERTOPT_PARENT;
    StartData.SessionType = SSF_TYPE_DEFAULT;
    StartData.IconFile    = 0;
    StartData.PgmHandle   = 0;
    StartData.InitXPos    = 30;
    StartData.InitYPos    = 40;
    StartData.InitXSize   = 200;
    StartData.InitYSize   = 140;
    StartData.Reserved    = 0;
    StartData.ObjectBuffer  = ObjBuf;
    StartData.ObjectBuffLen = 100;
 }

/**** JumpDir ***************************************************/
 void JumpDir(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0], "ディレクトリーのジャンプ                          ",50);
    memcpy(MsgTxt[13],"   I/Insert:登録   D/Delete:削除      Esc:取消    ",50);
    for (i=1;i<13;i++){
       memset(MsgTxt[i],0,50);
       MsgTxtLen[i]=50;
    }
    MsgTxtLen[0]=50; MsgTxtLen[13]=50; MsgTxtLen[14]=0;
    ShowMsgBox();
    ListBoxDisp();
    switch(KeyInfo.chChar){
       case ENTER:
          c=ListTxt[ix][2];
          DriveNo=(c<'a'?c-64:c-96);
          rc=DosSetDefaultDisk(DriveNo);
          if (rc) {ShowMsgDriveErr();return;}
          else rc=DosSetCurrentDir(ListTxt[ix]+2);
          if (rc) {ShowNewDrive();ShowMsgPassNo();}
          else ShowNewDrive();
          break;
       case 'i': case 'I':
          if (ix>4) {ShowMsgJunpDirErr(); JumpDir();}
          else {
             JUMPDIR=1;JumpDirInsert();
             if (KeyInfo.chChar==ESC) JumpDir();
          }
          break;
       case 'd': case 'D':
          JUMPDIR=1;JumpDirDelete();
          if (KeyInfo.chChar==ESC) JumpDir();
          break;
       case ESC: KeyInfo.chChar=0; break;
    }
 }

/**** JumpDirDelete *********************************************/
 void JumpDirDelete(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ジャンプ・ディレクトリー情報を削除します",40);
    memset(MsgTxt[1],0,40);
    memset(MsgTxt[2],0,40);
    memcpy(MsgTxt[3],"        Enter:実行      Esc:取消        ",40);
    MsgTxtLen[0]=40; MsgTxtLen[1]=40; MsgTxtLen[2]=40; MsgTxtLen[3]=40;
    MsgTxtLen[4]=0;
    strcpy(MsgTxt[1],ListTxt[ix]+2);
    MSGBOXKBDINWHILECR
    {
       memset(ListTxt[ix]+2,0,sizeof(ListTxt[0])-2);
       Fl=fopen(FlstrDirFl,s_w);
       for (i=0;i<11;i++) {
          fwrite(ListTxt[i]+2,strlen(ListTxt[i]+2),1,Fl);
          fwrite(sLF,1,1,Fl);
       }
       rc=fclose(Fl);
       if (JUMPDIR) JumpDir();
       else KbdLineInHist();
    }
 }

/**** JumpDirInsert *********************************************/
 void JumpDirInsert(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ジャンプ・ディレクトリーの登録            ",42);
    memset(MsgTxt[1],0,42);
    memset(MsgTxt[2],0,42);
    memset(MsgTxt[3],0,42);
    memcpy(MsgTxt[4],"         Enter:実行      Esc:取消         ",42);
    MsgTxtLen[0]=42; MsgTxtLen[1]=42; MsgTxtLen[2]=42; MsgTxtLen[3]=42;
    MsgTxtLen[4]=42; MsgTxtLen[5]=0;
    SetFullDirName();
    i=strlen(FulDirNm)-1;
    if (i>2&&FulDirNm[i]=='\\') memset(FulDirNm+i,0,1);
    /*if (InpLine[0])*/
    strcpy(InpLine,FulDirNm);
    /*else strcpy(InpLine,ListTxt[ix]+2);*/
    Indent=0;LineSeq=2;MSGBOXINPUTLINE
    {
       memset(ListTxt[ix]+2,0,sizeof(ListTxt[0])-2);
       strcpy(ListTxt[ix]+2,InpLine);
       Fl=fopen(FlstrDirFl,s_w);
       for (i=0;i<11;i++) {
          fwrite(ListTxt[i]+2,strlen(ListTxt[i]+2),1,Fl);
          fwrite(sLF,1,1,Fl);
       }
       rc=fclose(Fl);
       if (JUMPDIR) JumpDir();
       else KbdLineInHist();
    }
 }

/**** JumpDirRead ***********************************************/
 void JumpDirRead(void)
 {
    Fl=fopen(FlstrDirFl,"r"); if (Fl==NULL) return;
    IniFileBuf=fgets(ListTxt[0]+2,sizeof(ListTxt[0]),Fl);
    IniFileEnd=strchr(ListTxt[0]+2,'\n');memset(IniFileEnd,0,1);
    for (i=1;IniFileBuf&&i<11;i++){
       IniFileBuf=fgets(ListTxt[i]+2,sizeof(ListTxt[0]),Fl);
       if (IniFileBuf) {IniFileEnd=strchr(ListTxt[i]+2,'\n');memset(IniFileEnd,0,1);}
    }
    rc=fclose(Fl);
 }

/**** JumpHistInsert ********************************************/
 void JumpHistInsert(void)
 {
    for (i=10,j=1,AssocFind=0;i>4&&j;i--){
       if (ListTxt[i][2]==' '||ListTxt[i][2]==0) break;
       if (j=strcmp(ListTxt[i]+2,InpLine));
       else AssocFind=1;
    }
    if (!AssocFind){
       for (;i<10;++i) {
          memset(ListTxt[i]+2,0,sizeof(ListTxt[i])-2);
          strcpy(ListTxt[i]+2,ListTxt[i+1]+2);
       }
       memset(ListTxt[10]+2,0,sizeof(ListTxt[10])-2); strcpy(ListTxt[10]+2,InpLine);
    }
    Fl=fopen(FlstrDirFl,s_w);
    for (i=0;i<11;i++) {
       fwrite(ListTxt[i]+2,strlen(ListTxt[i]+2),1,Fl); fwrite(sLF,1,1,Fl);
    }
    rc=fclose(Fl);
 }

/**** KbdEvent **************************************************/
 void KbdEvent(void)
 {
    memset(InpLine,0,sizeof(InpLine)); Jump=0;
    memset(StartData.ObjectBuffer,0,1);
    if (KeyInfo.bNlsShift!=0&&KeyInfo.bNlsShift!=64) return;
    if (KeyInfo.fsState&LSHIFT||KeyInfo.fsState&RSHIFT) {
       if (KeyInfo.chChar==ENTER&&(FlDis[SelFl].Atr&ATTR_DIR)){
          SetFullFileName();
          HObj=WinQueryObject(FulFlNm);
          rc=WinSetObjectData(HObj,"OPEN=DEFAULT");
       }
       if (KeyInfo.chChar<'A'
           || (KeyInfo.chChar>'Z'&&KeyInfo.chChar<'a')
           || KeyInfo.chChar>'z') return;
       ix=KeyInfo.chChar>'Z'?KeyInfo.chChar-97:KeyInfo.chChar-65;
       if (ShiftPgmName[ix][0]!=0) {MacroFunc();return;}
    }
    switch(KeyInfo.chChar){
       case ENTER:
          if (MarkCnt) {MarkFileExec();return;}
          if (FlDis[SelFl].Atr&ATTR_DIR){
             if (!DosSetCurrentDir(FlDis[SelFl].Nm+29)){
                if (!memcmp(FlDis[SelFl].Nm+29,"..",2)) PrevSearch=1;
                QDir();
                QFile();
                if (PrevSearch) {PrevDirSearch();ShowType=0;}
                else {SelFl=StartFl=0;ShowType=1;}
                ShowFileList();
                PrevSearch=0;
             } else;
          }
          else if (strstr(FlDis[SelFl].Nm+29,c_EXE)||strstr(FlDis[SelFl].Nm+29,c_exe)
                 ||strstr(FlDis[SelFl].Nm+29,c_CMD)||strstr(FlDis[SelFl].Nm+29,c_cmd)
                 ||strstr(FlDis[SelFl].Nm+29,c_COM)||strstr(FlDis[SelFl].Nm+29,c_com))
               /*||strstr(FlDis[SelFl].Nm+29,c_BAT)||strstr(FlDis[SelFl].Nm+29,c_bat))*/
             ExecProgram();
          else if (strstr(FlDis[SelFl].Nm+29,c_INF)||strstr(FlDis[SelFl].Nm+29,c_inf))
             ViewInfFile();
          else {AssocFind=0;ExecAssocProgram();
             if (!AssocFind) ViewFile();
          }
          break;
       case ESC: QuitFilestar(); break;
       case BACK:
          rc=DosSetCurrentDir("..");
          if (!rc){
             QDir(); QFile(); PrevDirSearch(); ShowType=0; ShowFileList();
             PrevSearch=0;
          }
          break;
       case '\\':
          rc=DosSetCurrentDir("\\");
          QDir(); QFile(); SelFl=StartFl=0; ShowType=1; ShowFileList();
          break;
       case KEY1: case KEY2: case KEY3: case KEY4: case KEY5:
       case KEY6: case KEY7: case KEY8: case KEY9:
          DriveNo=KeyInfo.chChar-48;
          rc=DosSetDefaultDisk(DriveNo);
          switch(rc){
             case NO_ERROR: ShowNewDrive(); break;
             default: ShowMsgDriveErr();
          }
          break;
       case 'a': case 'A':
          if (MarkCnt) MarkFileAttribute();
          else if ((memcmp(FlDis[SelFl].Nm+29,"..",2))&&!(FlDis[SelFl].Atr&ATTR_DIR))
             ChangeAttribute();
          break;
       case 'c': case 'C': Jump=1;
          if (MarkCnt) MarkFileCopy();
          else if (memcmp(FlDis[SelFl].Nm+29,"..",2)) FileCopy();
          break;
       case 'd': case 'D':
          if (MarkCnt) MarkFileDelete();
          else if (memcmp(FlDis[SelFl].Nm+29,"..",2)) FileDelete();
          break;
       case 'e': case 'E': FileEdit(); break;
       case 'f': case 'F': FileFind(); break;
       case 'i': case 'I':
          if (MarkCnt) MarkFileIcon();
          else MakeIcon();
          break;
       case 'j': case 'J': Jump=1; JumpDir(); break;
       case 'k': case 'K': CreateDir(); break;
       case 'l': case 'L': ChangeDrive(); break;
       case 'm': case 'M': Jump=1;
          if (MarkCnt) MarkFileMove();
          else if (memcmp(FlDis[SelFl].Nm+29,"..",2)) FileMove();
          break;
       case 'n': case 'N':
          if (memcmp(FlDis[SelFl].Nm+29,"..",2)) FileName(); break;
       case 'o': case 'O': Jump=1;
          if (memcmp(FlDis[SelFl].Nm+29,"..",2)) FileXCopy(); break;
       case 'q': case 'Q': QuitFilestar(); break;
       case 's': case 'S': FileSort(); break;
       case 'v': case 'V':
          if (!(FlDis[SelFl].Atr&ATTR_DIR)) ViewFile();
          break;
       case 'x': case 'X': ExecCommand(); break;
       case 'y': case 'Y': FileMaskDisp(); break;
       case 'w': case 'W': ChangeWindowSize(); break;
       case '.': CommandProcess(); break;
       case '@': 
          if (FlDis[SelFl].Atr&ATTR_DIR){
             FlSize=0;FirstDisp=1;SelFlSv=SelFl;
             SummarySize(FlDis[SelFl].Nm+29);
             SelFl=SelFlSv;
             ShowSummarySize();
          }
          break;
       default : FuncEvent();
    }
 }

/**** KbdLineIn *************************************************/
 void KbdLineIn(void)
 {
    /*i:開始位置,CmdParm:ｶｰｿﾙ以降の文字列,jはその長さ*/
    InpLineLen=strlen(InpLine); i=Col; Col+=InpLineLen;
    memset(CmdParm,0,sizeof(CmdParm)); j=0;
    VioWrtCharStr(InpLine,InpLineLen,BoxTop+LineSeq+2,i,hvio);
    VioSetCurPos(BoxTop+LineSeq+2,Col,hvio);
    CursorInfo.yStart=-90;
    CursorInfo.cEnd  =-100;
    CursorInfo.attr=0;
    VioSetCurType(&CursorInfo,hvio);
    do {
       KbdCharIn(&KeyInfo,IO_WAIT,0);
       switch (KeyInfo.chChar){
          case ENTER: break;
          case ESC: break;
          case BACK:
             if (Col>i){
                VioSetCurPos(BoxTop+LineSeq+2,--Col,hvio);
                memcpy(InpLine+(Col-i),CmdParm,j+1);
                VioWrtNChar (" ",1,BoxTop+LineSeq+2,i+(--InpLineLen),hvio);
                VioWrtCharStr(InpLine,InpLineLen,BoxTop+LineSeq+2,i,hvio);
             }
             break;
          case ARROW: case PFK:
             switch (KeyInfo.chScan){
                case HOME:
                   VioSetCurPos(BoxTop+LineSeq+2,Col=i,hvio);
                   memcpy(CmdParm,InpLine,j=InpLineLen); memset(CmdParm+j,0,1);
                   break;
                case END:
                   VioSetCurPos(BoxTop+LineSeq+2,Col=i+InpLineLen,hvio);
                   j=0; memset(CmdParm+j,0,1);
                   break;
                case ARROW_UP:
                   if (Jump){
                      CursorInfo.attr=-1;VioSetCurType(&CursorInfo,hvio);
                      KbdLineInHist();
                      return;
                   }
                   break;
                case ARROW_LEFT:
                   if (Col>i){
                      VioSetCurPos(BoxTop+LineSeq+2,--Col,hvio);
                      memcpy(CmdParm,InpLine+(Col-i),++j); memset(CmdParm+j,0,1);
                   }
                   break;
                case ARROW_RIGHT:
                   if (Col<i+InpLineLen){
                      VioSetCurPos(BoxTop+LineSeq+2,++Col,hvio);
                      memcpy(CmdParm,InpLine+(Col-i),--j); memset(CmdParm+j,0,1);
                   }
                   break;
                case DELETE:
                   if (j){
                      memcpy(CmdParm,InpLine+(Col-i)+1,--j);
                      memcpy(InpLine+(Col-i),CmdParm,j);
                      memset(InpLine+(--InpLineLen),0,1);
                      VioWrtNChar (" ",1,BoxTop+LineSeq+2,i+InpLineLen,hvio);
                      VioWrtCharStr(InpLine,InpLineLen,BoxTop+LineSeq+2,i,hvio);
                   }
                   break;
                default:;
             }
             break;
          default:
             if (Col<BoxLeft+BoxWide-3){
                InpLine[(++Col-i)-1]=KeyInfo.chChar;
                memcpy(InpLine+(Col-i),CmdParm,j);
                VioWrtCharStr(InpLine,++InpLineLen,BoxTop+LineSeq+2,i,hvio);
                VioSetCurPos (BoxTop+LineSeq+2,Col,hvio);
             }
       }
    } while(KeyInfo.chChar!=ENTER&&KeyInfo.chChar!=ESC);
    CursorInfo.attr=-1;VioSetCurType(&CursorInfo,hvio);
 }

/**** KbdLineInHist *********************************************/
 void KbdLineInHist(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0], "宛先ディレクトリーの選択                          ",50);
    memcpy(MsgTxt[13],"   I/Insert:登録   D/Delete:削除      Esc:取消    ",50);
    MsgTxtLen[0]=50; MsgTxtLen[13]=50; MsgTxtLen[14]=0;
    for (i=1;i<13;i++){
       memset(MsgTxt[i],0,50);
       MsgTxtLen[i]=50;
    }
    ShowMsgBox();
    ListBoxDisp();
    switch(KeyInfo.chChar){
       case ENTER:
          strcpy(InpLine,ListTxt[ix]+2);
          break;
       case 'i': case 'I':
          if (ix>4) {ShowMsgJunpDirErr(); KbdLineInHist();}
          else {JUMPDIR=0;JumpDirInsert();}
          break;
       case 'd': case 'D':
          JUMPDIR=0;JumpDirDelete();
          break;
       case ESC: break;
    }
    KeyInfo.chChar=KeyInfo.chScan=0;
 }

/**** ListBoxDisp ************************************************/
 void ListBoxDisp(void)
 {
    for (i=0,Loop=1;i<10;i++) VioWrtCharStrAtt(ListTxt[i],BoxWide-6,BoxTop+i+3,BoxLeft+3,GrayWhite,hvio);
    VioWrtCharStrAtt(ListTxt[ix=10],BoxWide-6,BoxTop+13,BoxLeft+3,WhiteGray,hvio);
    do{
       KbdCharIn(&KeyInfo,IO_WAIT,0);
       switch(KeyInfo.chChar){
          case ENTER:
             if (ListTxt[ix][2]!=0&&ListTxt[ix][2]!=' ') Loop=0;
             break;
          case ESC: Loop=0; break;
          case 'i': case 'I': case 'd': case 'D': Loop=0; break;
          default: ListBoxDispFunc();
       }
    } while(Loop); {MSGBOXCLEAR}
 }


/**** ListBoxDispFunc*********************************************/
 void ListBoxDispFunc(void)
 {
    switch(KeyInfo.chScan){
       case 2: case 3: case 4: case 5: case 6:
          VioWrtCharStrAtt(ListTxt[ix],BoxWide-6,BoxTop+ix+3,BoxLeft+3,GrayWhite,hvio);
          ix=KeyInfo.chScan-2;
          VioWrtCharStrAtt(ListTxt[ix],BoxWide-6,BoxTop+ix+3,BoxLeft+3,WhiteGray,hvio);
          if (ListTxt[ix][2]!=0&&ListTxt[ix][2]!=' '){
             KeyInfo.chChar=ENTER; Loop=0;
          }
          break;
       case ARROW_UP:
          if (ix>0){
             VioWrtCharStrAtt(ListTxt[ix],BoxWide-6,BoxTop+ix+3,BoxLeft+3,GrayWhite,hvio);
             VioWrtCharStrAtt(ListTxt[--ix],BoxWide-6,BoxTop+ix+3,BoxLeft+3,WhiteGray,hvio);
          }
          break;
       case ARROW_DOWN:
          if (ix<10){
             VioWrtCharStrAtt(ListTxt[ix],BoxWide-6,BoxTop+ix+3,BoxLeft+3,GrayWhite,hvio);
             VioWrtCharStrAtt(ListTxt[++ix],BoxWide-6,BoxTop+ix+3,BoxLeft+3,WhiteGray,hvio);
          }
          break;
       case HOME:
          VioWrtCharStrAtt(ListTxt[ix],BoxWide-6,BoxTop+ix+3,BoxLeft+3,GrayWhite,hvio);
          VioWrtCharStrAtt(ListTxt[ix=0],BoxWide-6,BoxTop+ix+3,BoxLeft+3,WhiteGray,hvio);
          break;
       case END:
          VioWrtCharStrAtt(ListTxt[ix],BoxWide-6,BoxTop+ix+3,BoxLeft+3,GrayWhite,hvio);
          VioWrtCharStrAtt(ListTxt[ix=10],BoxWide-6,BoxTop+ix+3,BoxLeft+3,WhiteGray,hvio);
          break;
       case INSERT: KeyInfo.chChar='i'; Loop=0; break;
       case DELETE: KeyInfo.chChar='d'; Loop=0; break;
       default:;
    }
 }

/**** MacroDisp **************************************************/
 void MacroDisp(void)
 {
    BoxLineAttr=GrayBBlue;
    memset(MsgTxt[0],0,sizeof(MsgTxt[0]));
    memcpy(MsgTxt[0], "マクロの実行 [Shift+]",21);
    for (i=1;i<14;++i) {
       memset(MsgTxt[i],0,sizeof(MsgTxt[0]));
       memset(MsgTxt[i],i+64,1);
       memset(MsgTxt[i]+33,i+77,1);
       if (ShiftPgmName[i-1][0]!=0){
          if (LShiftSession[i-1]) memcpy(MsgTxt[i]+1,"SS1:",4);
          else memcpy(MsgTxt[i]+1,"SS0:",4);
          strcpy(MsgTxt[i]+5,ShiftPgmName[i-1]);
          strcat(MsgTxt[i]+5,ShiftParm[i-1]);
       }
       if (ShiftPgmName[i+12][0]!=0){
          if (LShiftSession[i+12]) memcpy(MsgTxt[i]+34,"SS1:",4);
          else memcpy(MsgTxt[i]+34,"SS0:",4);
          strcpy(MsgTxt[i]+38,ShiftPgmName[i+12]);
          strcat(MsgTxt[i]+38,ShiftParm[i+12]);
       }
    }
    MsgTxtLen[0]=70; MsgTxtLen[1]=70; MsgTxtLen[2]=70; MsgTxtLen[3]=70;
    MsgTxtLen[4]=70; MsgTxtLen[5]=70; MsgTxtLen[6]=70; MsgTxtLen[7]=70;
    MsgTxtLen[8]=70; MsgTxtLen[9]=70; MsgTxtLen[10]=70; MsgTxtLen[11]=70;
    MsgTxtLen[12]=70; MsgTxtLen[13]=70; MsgTxtLen[14]=0;
    ShowMsgBox();
    for (i=1;i<14;++i) {
       VioWrtCharStrAtt(MsgTxt[i],1,BoxTop+2+i,BoxLeft+3,WhiteBright,hvio);
       VioWrtCharStrAtt(MsgTxt[i]+33,1,BoxTop+2+i,BoxLeft+36,WhiteBright,hvio);
    }
    for (;;) {
       KbdCharIn(&KeyInfo,IO_WAIT,0);
       if (KeyInfo.chChar==ESC) break;
       else if (KeyInfo.chChar<'A'
               || (KeyInfo.chChar>'Z'&&KeyInfo.chChar<'a')
               ||  KeyInfo.chChar>'z') ;
       else {
          ix=KeyInfo.chChar>'Z'?KeyInfo.chChar-97:KeyInfo.chChar-65;
          if (ShiftPgmName[ix][0]!=0) break;
       }
    }
    MSGBOXCLEAR
    if (KeyInfo.chChar!=ESC) MacroFunc();
 }

/**** MacroFunc **************************************************/
 void MacroFunc(void)
 {
    BoxLineAttr=GrayBBlue;
    memset(MsgTxt[0],0,sizeof(MsgTxt[0]));
    memcpy(MsgTxt[0],"マクロ機  を実行します           ",26);
    memcpy(MsgTxt[0]+8,Noh,2);
    memset(MsgTxt[1],0,sizeof(MsgTxt[1]));
    memset(MsgTxt[2],0,sizeof(MsgTxt[2]));
    memcpy(MsgTxt[3],"       Enter:実行  Esc:取消      ",26);
    MsgTxtLen[0]=40; MsgTxtLen[1]=40; MsgTxtLen[2]=40; MsgTxtLen[3]=0;
    MsgTxtLen[4]=0;
    ExecAssocProgramParm(ShiftParm[ix]);
    strcpy(MsgTxt[2],ShiftPgmName[ix]);
    strcat(MsgTxt[2],ObjTitle);
    MSGBOXKBDINWHILECR
    {
       MSGBOXCLEAR
       rc=DosQueryPathInfo(ShiftPgmName[ix],1,&PathInfo3,sizeof(FILESTATUS3));
       if (rc) rc=FilePathSearch(ShiftPgmName[ix]);/*絶対名がFulFlNmへ*/
       if (rc){
          strcpy(StartData.ObjectBuffer,ShiftPgmName[ix]);
          ShowMsgExecNotF();return;
       }
       ExecAssocProgramFunc(LShiftSession[ix],ShiftPgmName[ix]);
    }
 }

/**** MacroSetup *************************************************/
 void MacroSetup(void)
 {
    SEARCHINIFILEEND2
    if (!memcmp(IniFileIn,"Shift",5)) MacroSetupShift();
    else if (!memcmp(IniFileIn,"RCtrl",5));
    else if (!memcmp(IniFileIn,"LAlt",4));
    else if (!memcmp(IniFileIn,"RAlt",4));
 }

/**** MacroSetupShift ********************************************/
 void MacroSetupShift(void)
 {
    if (IniFileIn[6]<'A'
       || (IniFileIn[6]>'Z'&&IniFileIn[6]<'a')
       || IniFileIn[6]>'z') return;
    ix=IniFileIn[6]>'Z'?IniFileIn[6]-97:IniFileIn[6]-65;
    if ((!memcmp(IniFileIn+8,"SS1",3))||(!memcmp(IniFileIn+8,"ss1",3))) LShiftSession[ix]=1;
    else if ((!memcmp(IniFileIn+8,"SS0",3))||(!memcmp(IniFileIn+8,"ss0",3))) LShiftSession[ix]=0;
    else return;
    if (s=strchr(IniFileIn+12,' ')){
       memcpy(ShiftPgmName[ix],IniFileIn+12,s-IniFileIn-11);
       memcpy(ShiftParm[ix],s+1,IniFileEnd-s-1);
       if (s=strstr(ShiftParm[ix],"&f")) memcpy(s,"&F",2);
    }
    else memcpy(ShiftPgmName[ix],IniFileIn+12,IniFileEnd-IniFileIn-11);
 }

/**** MakeIcon ***************************************************/
 void MakeIcon(void)
 {
    SETFILE1STNAMEINPUTLINE
    if (strstr(FlDis[SelFl].Nm+29,c_EXE)||strstr(FlDis[SelFl].Nm+29,c_exe)
      ||strstr(FlDis[SelFl].Nm+29,c_CMD)||strstr(FlDis[SelFl].Nm+29,c_cmd)
      ||strstr(FlDis[SelFl].Nm+29,c_COM)||strstr(FlDis[SelFl].Nm+29,c_com)
      ||strstr(FlDis[SelFl].Nm+29,c_BAT)||strstr(FlDis[SelFl].Nm+29,c_bat))
       if (ByPass) MakePrgIconFunc(); else MakePrgIcon();
    else if(strstr(FlDis[SelFl].Nm+29,c_INF)||strstr(FlDis[SelFl].Nm+29,c_inf))
       if (ByPass) MakeInfIconFunc(); else MakeInfIcon();
    else if (!memcmp(FlDis[SelFl].Nm+29,"..",2));
    else if (ByPass) MakeShadowIconFunc(); else MakeShadowIcon();
 }

/**** MakeInfIcon ************************************************/
 void MakeInfIcon(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"デスクトップにＩＮＦアイコンを登録します",40);
    memcpy(MsgTxt[1],"Object:                                 ",40);
    memset(MsgTxt[2],0,40);
    memcpy(MsgTxt[3],"タイトルを指定して下さい（改行は^)      ",40);
    memset(MsgTxt[4],0,40);
    memset(MsgTxt[5],0,40);
    memcpy(MsgTxt[6],"      Enter:実行  Esc:取消              ",40);
    memcpy(MsgTxt[1]+7,FlDis[SelFl].Nm+29,strlen(FlDis[SelFl].Nm+29));
    MsgTxtLen[0]=40; MsgTxtLen[1]=40; MsgTxtLen[2]=40; MsgTxtLen[3]=40;
    MsgTxtLen[4]=40; MsgTxtLen[5]=40; MsgTxtLen[6]=40; MsgTxtLen[7]=0;
    Indent=0;LineSeq=4;MSGBOXINPUTLINE
    {
       MSGBOXCLEAR
       MakeInfIconFunc();
       if (HObj!=NULLHANDLE) ShowMsgIconOk();
       else ShowMsgIconErr();
    }
 }

/**** MakeInfIconFunc ********************************************/
 void MakeInfIconFunc(void)
 {
    memcpy(ObjClassName,"WPProgram",10);
    memcpy(ObjTitle,InpLine,InpLineLen+1);
    SetFullFileName();
    memcpy(ObjSetupString1+8,"VIEW.EXE;PARAMETERS=",20);
    memcpy(ObjSetupString1+28,FulFlNm,i=strlen(FulFlNm));
    memcpy(ObjSetupString1+28+i,";",2);
    HObj=WinCreateObject(ObjClassName,ObjTitle,ObjSetupString1,ObjLocation,ObjMode);
 }

/**** MakeShadowIcon *********************************************/
 void MakeShadowIcon(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ﾃﾞｽｸﾄｯﾌﾟにｼｬﾄﾞｳｱｲｺﾝを登録します",31);
    memcpy(MsgTxt[1],"Object:                        ",31);
    memset(MsgTxt[2],0,31);
    memset(MsgTxt[2],0,31);
    memcpy(MsgTxt[3],"     Enter:実行    Esc:取消    ",31);
    memcpy(MsgTxt[1]+7,FlDis[SelFl].Nm+29,strlen(FlDis[SelFl].Nm+29));
    MsgTxtLen[0]=31; MsgTxtLen[1]=31; MsgTxtLen[2]=31; MsgTxtLen[3]=31;
    MsgTxtLen[4]=0;
    MSGBOXKBDINWHILECR
    {
       MSGBOXCLEAR
       MakeShadowIconFunc();
       if (HObj!=NULLHANDLE) ShowMsgIconOk();
       else ShowMsgIconErr();
    }
 }

/**** MakeShadowIconFunc *****************************************/
 void MakeShadowIconFunc(void)
 {
    memcpy(ObjClassName,"WPShadow",10);
    SetFullFileName();
    memcpy(ObjSetupString2+9,FulFlNm,i=strlen(FulFlNm));
    memset(ObjSetupString2+9+i,';',1);
    HObj = WinCreateObject(ObjClassName,ObjTitle,ObjSetupString2,ObjLocation,ObjMode);
 }

/**** MakePrgIcon ************************************************/
 void MakePrgIcon(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"デスクトップにプログラムアイコンを登録します",44);
    memcpy(MsgTxt[1],"Object:                                     ",44);
    memset(MsgTxt[2],0,44);
    memcpy(MsgTxt[3],"タイトルを指定して下さい（改行は^)          ",44);
    memset(MsgTxt[4],0,44);
    memset(MsgTxt[5],0,44);
    memcpy(MsgTxt[6],"       Enter:実行     Esc:取消              ",42);
    memcpy(MsgTxt[1]+7,FlDis[SelFl].Nm+29,strlen(FlDis[SelFl].Nm+29));
    MsgTxtLen[0]=44; MsgTxtLen[1]=44; MsgTxtLen[2]=44; MsgTxtLen[3]=44;
    MsgTxtLen[4]=44; MsgTxtLen[5]=44; MsgTxtLen[6]=44; MsgTxtLen[7]=0;
    Indent=0;LineSeq=4;MSGBOXINPUTLINE
    {
       MSGBOXCLEAR
       MakePrgIconFunc();
       if (HObj!=NULLHANDLE) ShowMsgIconOk();
       else ShowMsgIconErr();
    }
 }

/**** MakePrgIconFunc ********************************************/
 void MakePrgIconFunc(void)
 {
    memcpy(ObjClassName,"WPProgram",10);
    memcpy(ObjTitle,InpLine,InpLineLen+1);
    SetFullFileName();
    memcpy(ObjSetupString1+8,FulFlNm,i=strlen(FulFlNm));
    memcpy(ObjSetupString1+8+i,";",2);
    HObj = WinCreateObject(ObjClassName,ObjTitle,ObjSetupString1,ObjLocation,ObjMode);
 }

/**** MarkFileAttribute *****************************************/
 void MarkFileAttribute(void)
 {
    USHORT im;
    AttrSys=AttrHidden=AttrROnly=0;
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"★マークファイルの属性を変更します  ",36);
    memcpy(MsgTxt[1],"                                    ",36);
    memcpy(MsgTxt[2],"変更する属性の番号キーを押して下さい",36);
    memcpy(MsgTxt[3],"  1.□システム・ファイル            ",36);
    memcpy(MsgTxt[4],"  2.□隠しファイル                  ",36);
    memcpy(MsgTxt[5],"  3.□リード・オンリー              ",36);
    memcpy(MsgTxt[6],"                                    ",36);
    memcpy(MsgTxt[7],"     Enter:実行    Esc:取消         ",36);
    MsgTxtLen[0]=36; MsgTxtLen[1]=36; MsgTxtLen[2]=36; MsgTxtLen[3]=36;
    MsgTxtLen[4]=36; MsgTxtLen[5]=36; MsgTxtLen[6]=36; MsgTxtLen[7]=36;
    MsgTxtLen[8]=0;
    ShowMsgBox();
    do{
       KbdCharIn(&KeyInfo,IO_WAIT,0);
       ChangeAttributeFunc(3);
    } while(KeyInfo.chChar!=ESC&&KeyInfo.chChar!=ENTER);
    if (KeyInfo.chChar==ENTER){
       MSGBOXCLEAR
       for (im=0;im<FlCnt&&KeyInfo.chChar!=ESC;++im) if (FlMark[im]){
          KbdCharIn(&KeyInfo,IO_NOWAIT,0);
          FirstDisp=1;ChangeAttributeDisp(FlDis[im].Nm+29);
          rc=DosQueryPathInfo(FlDis[im].Nm+29,1,&PathInfo3,sizeof(FILESTATUS3));
          if (AttrSys) PathInfo3.attrFile|=ATTR_SYSTEM; else PathInfo3.attrFile&=ATTR_SYSTEM_REV;
          if (AttrHidden) PathInfo3.attrFile|=ATTR_HIDDEN; else PathInfo3.attrFile&=ATTR_HIDDEN_REV;
          if (AttrROnly) PathInfo3.attrFile|=ATTR_READONLY; else PathInfo3.attrFile&=ATTR_READONLY_REV;
          rc=DosSetPathInfo(FlDis[im].Nm+29,1,&PathInfo3,sizeof(FILESTATUS3),0);
       } 
       SETPREVFILE
    }
    MSGBOXCLEAR
 }

/**** MarkFileCopy **********************************************/
 void MarkFileCopy(void)
 {
    USHORT im;
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"★マークファイルをコピーします                    ",50);
    memset(MsgTxt[1],0,sizeof(MsgTxt[0]));
    memcpy(MsgTxt[2],"コピー先を指定して下さい            (↑ｷｰでﾋｽﾄﾘｰ) ",50);
    memset(MsgTxt[3],0,sizeof(MsgTxt[0]));
    memset(MsgTxt[4],0,sizeof(MsgTxt[0]));
    memcpy(MsgTxt[5],"            Enter:実行      Esc:取消              ",50);
    MsgTxtLen[0]=50; MsgTxtLen[1]=50; MsgTxtLen[2]=50; MsgTxtLen[3]=50;
    MsgTxtLen[4]=50; MsgTxtLen[5]=50; MsgTxtLen[6]=0;
    Indent=0;LineSeq=3;MSGBOXINPUTLINE
    {
       while(!KeyInfo.chChar&&!KeyInfo.chScan){MarkFileCopy();return;}
       MSGBOXCLEAR OverWrite=RESET;ByPass=0;
       SameDirCheck(); if (rc) return;
       if (!strlen(InpLine)) {ShowMsgNameNg();return;}
       for (i=0,FlCntSv=FlCnt;i<FlCnt;++i){
          FlMarkSv[i]=FlMark[i]; AtrSv[i]=FlDis[i].Atr;
          strcpy(FlNmSv[i],FlDis[i].Nm+29); memcpy(FlTimeSv[i],FlDis[i].Nm+13,14);
       }
       FirstDisp=1;rc=0;
       for (im=0;im<FlCntSv&&!rc&&KeyInfo.chChar!=ESC;++im) if (FlMarkSv[im]){
          KbdCharIn(&KeyInfo,IO_NOWAIT,0);
          if (AtrSv[im]&ATTR_DIR) {DirCopy=1;FileCopyDir(FlNmSv[im]);}
          else {DirCopy=0;FileCopyFl(FlNmSv[im],FlTimeSv[im]);}
          /*QDriveSize();*/
       }
       MSGBOXCLEAR
       if (ByPass) {ByPass=0;return;}
       FileCopyRc();
       JumpHistInsert();
    }
 }

/**** MarkFileDelete ********************************************/
 void MarkFileDelete(void)
 {
    USHORT im; APIRET rca;
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"★マークファイルを削除します",28);
    memcpy(MsgTxt[1],"                            ",28);
    memcpy(MsgTxt[2],"  Ｙ:yes(Enter)  Ｎ:no(Esc) ",28);
    MsgTxtLen[0]=28; MsgTxtLen[1]=28; MsgTxtLen[2]=28; MsgTxtLen[3]=0;
    MSGBOXKBDINWHILE(KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y
                   &&KeyInfo.chChar!=c_N&&KeyInfo.chChar!=c_n
                   &&KeyInfo.chChar!=ENTER);
    MSGBOXCLEAR ByPass=0;
    if (KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y&&KeyInfo.chChar!=ENTER) return;
    for (i=0,FlCntSv=FlCnt;i<FlCnt;++i){
       FlMarkSv[i]=FlMark[i]; strcpy(FlNmSv[i],FlDis[i].Nm+29); AtrSv[i]=FlDis[i].Atr;
    }
    FirstDisp=1;rc=0;
    for (im=0;im<FlCntSv&&!rc&&KeyInfo.chChar!=ESC;++im) if (FlMarkSv[im]){
       KbdCharIn(&KeyInfo,IO_NOWAIT,0);
       FileDeleteFunc(FlNmSv[im],AtrSv[im]);rca=rc;QFile();
       QDriveSize();
    }
    ReDrawAfterDelete();
    if (rca) rc=rca;
    FileDeleteRc();
 }

/**** MarkFileExec **********************************************/
 void MarkFileExec(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"★マークファイルの連続実行を行います",36);
    memcpy(MsgTxt[1],"   (拡張子関連付けﾌﾟﾛｸﾞﾗﾑのみ)      ",36);
    memset(MsgTxt[2],0,sizeof(MsgTxt[2]));
    memcpy(MsgTxt[3],"     Ｙ:yes(Enter)   Ｎ:no(Esc)     ",36);
    MsgTxtLen[0]=36; MsgTxtLen[1]=36; MsgTxtLen[2]=36; MsgTxtLen[3]=36;
    MsgTxtLen[4]=0;
    MSGBOXKBDINWHILE(KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y
                   &&KeyInfo.chChar!=c_N&&KeyInfo.chChar!=c_n
                   &&KeyInfo.chChar!=ENTER);
    MSGBOXCLEAR FlMove=0;
    if (KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y&&KeyInfo.chChar!=ENTER) return;
    SelFlSv=SelFl; ByPass=1; strcpy(PrevFl,FlDis[SelFl].Nm+29);
    for (LineSeq=0;LineSeq<FlCnt&&KeyInfo.chChar!=ESC;++LineSeq) if (FlMark[LineSeq]) if (!(FlDis[LineSeq].Atr&ATTR_DIR)){
       KbdCharIn(&KeyInfo,IO_NOWAIT,0);
       if (strstr(FlDis[LineSeq].Nm+29,c_EXE)||strstr(FlDis[LineSeq].Nm+29,c_exe)
         ||strstr(FlDis[LineSeq].Nm+29,c_CMD)||strstr(FlDis[LineSeq].Nm+29,c_cmd)
         ||strstr(FlDis[LineSeq].Nm+29,c_COM)||strstr(FlDis[LineSeq].Nm+29,c_com));
          /*{SelFl=LineSeq;ExecProgram();}*/
       else if (strstr(FlDis[LineSeq].Nm+29,c_INF)||strstr(FlDis[LineSeq].Nm+29,c_inf));
          /*{SelFl=LineSeq;ViewInfFile();}*/
       else {SelFl=LineSeq;AssocFind=0;ExecAssocProgram();}
    }
    MarkCnt=0; MarkSize=0;
    for(i=0;i<FlCnt;++i) {memcpy(FlDis[i].Nm+27,"  ",2);FlMark[i]=0;}
    SelFl=SelFlSv; ByPass=0; QFile(); PrevFileSearch();
    if (FlMove) {RedrawScreen();FlMove=0;}
    else {MSGBOXCLEAR}
 }

/**** MarkFileMove **********************************************/
 void MarkFileMove(void)
 {
    USHORT im; APIRET rca; UCHAR dirNm[124];
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"★マークファイルを移動します                      ",50);
    memset(MsgTxt[1],0,50);
    memcpy(MsgTxt[2],"移動先を指定して下さい              (↑ｷｰでﾋｽﾄﾘｰ) ",50);
    memset(MsgTxt[3],0,50);
    memset(MsgTxt[4],0,50);
    memcpy(MsgTxt[5],"    Enter:実行   Esc:取消                         ",50);
    MsgTxtLen[0]=50; MsgTxtLen[1]=50; MsgTxtLen[2]=50; MsgTxtLen[3]=50;
    MsgTxtLen[4]=50; MsgTxtLen[5]=50; MsgTxtLen[6]=0;
    Indent=0;LineSeq=3;MSGBOXINPUTLINE
    {
       while(!KeyInfo.chChar&&!KeyInfo.chScan){MarkFileMove();return;}
       MSGBOXCLEAR OverWrite=RESET;ByPass=0;
       SameDirCheck(); if (rc) return;
       SameDriveCheck();
       if (!strlen(InpLine)) {ShowMsgNameNg();return;}
       for (i=0,FlCntSv=FlCnt;i<FlCnt;++i){
          FlMarkSv[i]=FlMark[i]; AtrSv[i]=FlDis[i].Atr;
          strcpy(FlNmSv[i],FlDis[i].Nm+29); memcpy(FlTimeSv[i],FlDis[i].Nm+13,14); 
       }
       FirstDisp=1;
       for (im=0;im<FlCntSv&&!rc&&KeyInfo.chChar!=ESC;++im) if (FlMarkSv[im]){
          KbdCharIn(&KeyInfo,IO_NOWAIT,0);
          FlMove=1;
          if (AtrSv[im]&ATTR_DIR) {DirCopy=1;FileCopyDir(FlNmSv[im]);}
          else {DirCopy=0;FileCopyFl(FlNmSv[im],FlTimeSv[im]);}
          if (rc) {if (!ByPass&KeyInfo.chChar!=ESC) FileCopyRc();FlMove=0;return;}
          QDriveSize();
       }
       for (im=0;im<FlCntSv &&
                 ((!rc)||(rc==2)) &&
                 KeyInfo.chChar!=ESC;++im)
          if (FlMarkSv[im]){
             KbdCharIn(&KeyInfo,IO_NOWAIT,0);
             rc=DosQueryPathInfo(FlNmSv[im],1,&PathInfo3,sizeof(FILESTATUS3));
             switch(rc){
                case NO_ERROR: FileDeleteFunc(FlNmSv[im],AtrSv[im]); break;
                case ERROR_FILE_NOT_FOUND: rc=0; break;
                default: break;
             }
             rca=rc;QDriveSize();QFile();
          }
       if (rca) {rc=rca;FileDeleteRc();}
       ReDrawAfterDelete();
       if (KeyInfo.chChar==ESC) ShowMsgMoveStop();
       if (ByPass) {ByPass=0;return;}
       FlMove=0;
       JumpHistInsert();
    }
 }

/**** MarkFileIcon **********************************************/
 void MarkFileIcon(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"★ﾏｰｸﾌｧｲﾙの連続アイコン登録を行います",37);
    memcpy(MsgTxt[1],"                                     ",37);
    memcpy(MsgTxt[2],"     Ｙ:yes(Enter)   Ｎ:no(Esc)      ",37);
    MsgTxtLen[0]=37; MsgTxtLen[1]=37; MsgTxtLen[2]=37; MsgTxtLen[3]=0;
    MSGBOXKBDINWHILE(KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y
                   &&KeyInfo.chChar!=c_N&&KeyInfo.chChar!=c_n
                   &&KeyInfo.chChar!=ENTER);
    MSGBOXCLEAR
    SelFlSv=SelFl; ByPass=1; strcpy(PrevFl,FlDis[SelFl].Nm+29);
    for (LineSeq=0;LineSeq<FlCnt;++LineSeq) if (FlMark[LineSeq]){
       SelFl=LineSeq;
       ShowMsgIconReg();
       MakeIcon();
    }
    MarkCnt=0; MarkSize=0;
    for(i=0;i<FlCnt;++i) {memcpy(FlDis[i].Nm+27,"  ",2);FlMark[i]=0;}
    SelFl=SelFlSv; ByPass=0; QFile(); PrevFileSearch();
    MSGBOXCLEAR
 }

/**** PrevFileSearch ********************************************/
 void PrevFileSearch(void)
 {
    for (i=0,j=strlen(PrevFl)+1;i<FlCnt;++i)
       if (!memcmp(FlDis[i].Nm+29,PrevFl,j)) break;
    SelFl=(i==FlCnt ? 0:i);
    PageNo=((++i)+(RowMax-6))/(RowMax-5);
    StartFl=(PageNo-1)*(RowMax-5);
    Row=SaveRow=SelFl-StartFl+4;
 }

/**** PrevDirSearch *********************************************/
 void PrevDirSearch(void)
 {
    for (i=0,j=strlen(PrevDir)+1;i<FlCnt;++i)
       if (!memcmp(FlDis[i].Nm+29,PrevDir,j)) break;
    if (i==FlCnt) i=0;
    SelFl=i; PageNo=((++i)+(RowMax-6))/(RowMax-5);
    StartFl=(PageNo-1)*(RowMax-5);
    Row=SaveRow=SelFl-StartFl+4;
 }

/**** QDrive *****************************************************/
 void QDrive(void)
 {
    DriveNo=0;
    DosQueryCurrentDisk(&DriveNo,&DriveMap);
    DriveDis[0]=DriveChar[DriveNo-1];
    DosQueryFSInfo(DriveNo,FSInfoLevel2,FSInfoBuf,FSInfoBufSize);
    PFsInfo2=(pFsInfo2)FSInfoBuf;
    memset(Label,0,j=sizeof(Label));
    strcpy(Label,PFsInfo2->volumelabel);
    VioWrtCharStrAtt(Label,j,1,1,DarkYellow,hvio);
    VioWrtCharStrAtt(DriveDis,DriveDisLen,1,13,YellowBright,hvio);
    QDriveSize();
 }

/**** QDriveSize *************************************************/
 void QDriveSize(void)
 {
    DriveNo=0;
    rc=DosQueryFSInfo(DriveNo,FSInfoLevel1,FSInfoBuf,FSInfoBufSize);
    PFsInfo1=(pFsInfo1)FSInfoBuf;
    memset(FreeDis,0,j=sizeof(FreeDis));
    sprintf(FreeDis,"Free:%uK/%uK",
            PFsInfo1->bytesnum*PFsInfo1->sectornum*PFsInfo1->unitavail/1000,
            PFsInfo1->bytesnum*PFsInfo1->sectornum*PFsInfo1->unitnum/1000);
    if (46+j>ColMax) j=ColMax-46;
    VioWrtNChar(" ",j,2,46,hvio);
    VioWrtCharStrAtt(FreeDis,j,2,46,BlueBright,hvio);
 }

/**** QDir ******************************************************/
 void QDir(void)
 {
    memcpy(PrevDir,CurrDir,strlen(CurrDir)+1);
    memset(PathDis+1,0,sizeof(PathDis)-1);
    PathLen=124;rc=DosQueryCurrentDir(0,PathDis+1,&PathLen);
    VioWrtCharStrAtt(PathDis,ColMax-16,1,15,YellowBright,hvio);
    for (i=j=strlen(PathDis+1);i>0;--i) if (!memcmp(PathDis+i,"\\",1)) break;
    memcpy(CurrDir,PathDis+1+i,j-i+1);
 }

/**** QFile ******************************************************/
 void QFile(void)
 {
    FlCnt=0; PageNo=1; FindCnt=1; CurrentSize=0; MarkCnt=0; MarkSize=0;
    DirHandle=0x0001;
    rc=DosFindFirst(FlMask,&DirHandle,FlFindAtr,(PVOID)&FileInfo3,
                    sizeof(FileInfo3),&FindCnt,FIL_STANDARD);
    StartupDirErr=rc;
    if (!rc&&strcmp(FileInfo3.achName,".")) {FlCnt++;SetFileInfo();}
    while(rc==NO_ERROR) {
       rc=DosFindNext(DirHandle,(PVOID)&FileInfo3,
                      sizeof(FileInfo3),&FindCnt);
       if (!rc&&strcmp(FileInfo3.achName,".")) {FlCnt++;SetFileInfo();}
    }
    memset(FlCntDis+6,0,sizeof(FlCntDis)-6);
    sprintf(FlCntDis+6,"%4d(%uK)",FlCnt,CurrentSize/1000);
    memset(MarkCntDis+2,0,sizeof(MarkCntDis)-2);
    sprintf(MarkCntDis,"☆%d(%uK)",MarkCnt,MarkSize/1000);
    if (AlwaysSort) qsort(FlDis,FlCnt,sizeof(struct _FlDis),FileNameComp);
    rc=0;
 }

/**** QuitFilestar ***********************************************/
 void QuitFilestar()
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"  ★ＦｉｌｅＳｔａｒ★    ",26);
    memcpy(MsgTxt[1],"      を終了します        ",26);
    memcpy(MsgTxt[2],"                          ",26);
    memcpy(MsgTxt[3],"Ｙ:yes(Enter)   Ｎ:no(Esc)",26);
    MsgTxtLen[0]=26; MsgTxtLen[1]=26; MsgTxtLen[2]=26; MsgTxtLen[3]=26;
    MsgTxtLen[4]=0;
    MSGBOXKBDINWHILE(KeyInfo.chChar!=c_Y&&KeyInfo.chChar!=c_y
                  && KeyInfo.chChar!=c_N&&KeyInfo.chChar!=c_n
                  && KeyInfo.chChar!=ENTER);
    switch(KeyInfo.chChar){
       case ESC: MSGBOXCLEAR break;
       case ENTER:
       case 'Y': case 'y': puts(NORMAL); puts(CLEAR); DosExit(1,0); break;
       case 'N': case 'n': MSGBOXCLEAR break;
       default:;
    }
 }

/**** ReDrawAfterDelete ******************************************/
 void ReDrawAfterDelete(void)
 {
    QFile();
    if (!FlCnt) {ShowType=1;ShowFileList();}
    else if (SelFl>=FlCnt) ShowBottom();
    else {
       PageNo=((SelFl+1)+(RowMax-6))/(RowMax-5);
       StartFl=(PageNo-1)*(RowMax-5);
       SaveRow=SelFl-StartFl+4;
       ShowType=0;ShowFileList();
    }
 }

/**** RedrawScreen ***********************************************/
 void RedrawScreen(void)
 {
    SetWallColor();
    VioWrtCharStrAtt(Label,strlen(Label),1,1,DarkYellow,hvio);
    VioWrtCharStrAtt(DriveDis,DriveDisLen,1,13,YellowBright,hvio);
    VioWrtCharStrAtt(PathDis,ColMax-4,1,15,YellowBright,hvio);
    VioWrtCharStrAtt(FlCntDis,FlCntDisLen,2,1,BlueBright,hvio);
    j=sizeof(FreeDis); if (46+j>ColMax) j=ColMax-46;
    VioWrtNChar(" ",j,2,46,hvio);
    VioWrtCharStrAtt(FreeDis,j,2,46,BlueBright,hvio);
    ShowType=0;ShowFileList();
 }

/**** SameDirCheck ***********************************************/
 void SameDirCheck(void)
 {
    UCHAR currDir[124],toDir[124]; rc=0;
    if (!strcmp(InpLine,".")){
       ShowMsgSameDir(); rc=1; return;
    }
    memcpy(currDir,DriveDis,2); strcpy(currDir+2,PathDis);
    strupr(currDir); strupr(InpLine);
    if (!strcmp(InpLine,currDir)){
       ShowMsgSameDir(); rc=1; return;
    }
 }

/**** SameDriveCheck *********************************************/
 void SameDriveCheck(void)
 {
    SameDrive=0;
    if (s=strchr(InpLine,':')){
       /*1桁目の':'*/
       if (!(s-InpLine)) {ShowMsgNameNg();rc=ByPass=1;return;}
       c=toupper(InpLine[s-InpLine-1]);memset(s-1,c,1);
       if (!memcmp(s-1,DriveDis,1)) SameDrive=1;
    }
    else SameDrive=1;
 }

/**** Serch1Char *************************************************/
 void Serch1Char(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ファイル名の頭出しをします",26);
    memcpy(MsgTxt[1],"（カー  ル位置からの次）　",26);
    memcpy(MsgTxt[1]+6,So,2);
    memcpy(MsgTxt[2],"頭出文字キーを押して下さい",26);
    MsgTxtLen[0]=26; MsgTxtLen[1]=26; MsgTxtLen[2]=26; MsgTxtLen[3]=0;
    MSGBOXKBDINWHILE (KeyInfo.chChar<'A'
                  || (KeyInfo.chChar>'Z'&&KeyInfo.chChar<'a')
                  || KeyInfo.chChar>'z');
    if (KeyInfo.chChar==ESC) {MSGBOXCLEAR}
    else {
       MSGBOXCLEAR
       if (KeyInfo.chChar>'Z') KeyInfo.chChar-=32;
       for(i=SelFl+1;i<FlCnt;++i){
          j=FlDis[i].Nm[29]; if (j>'Z') j-=32;
          if (j==KeyInfo.chChar) break;
       }
       if (i==FlCnt) Serch1CharNg();
       else{
          SelFl=i; PageNo=((++i)+(RowMax-6))/(RowMax-5);
          StartFl=(PageNo-1)*(RowMax-5);
          SaveRow=SelFl-StartFl+4;MSGBOXCLEAR
       }
    }
 }

/**** Serch1CharNg ***********************************************/
 void Serch1CharNg(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"その文字で始まるファイルは",26);
    memcpy(MsgTxt[1],"この下にはもうありません　",26);
    MsgTxtLen[0]=26; MsgTxtLen[1]=26; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** SetFileInfo ************************************************/
 void SetFileInfo(void)
 {
    if (FlCnt<=FILE_MAX){
       memset(FlDis[FlCnt-1].Nm,' ',FILE_DISPLEN); FlMark[FlCnt-1]=0;
       sprintf(FlDis[FlCnt-1].Nm," %10d  %02.2d-%02.2d-%02.2d %02.2d:%02.2d  %s\0",
                                    FileInfo3.cbFile,
                                    (FileInfo3.fdateLastWrite.year+80)%100,
                                    FileInfo3.fdateLastWrite.month,
                                    FileInfo3.fdateLastWrite.day,
                                    FileInfo3.ftimeLastWrite.hours,
                                    FileInfo3.ftimeLastWrite.minutes,
                                    FileInfo3.achName);
       FlDis[FlCnt-1].Atr=FileInfo3.attrFile;
       if (FlDis[FlCnt-1].Atr&ATTR_DIR) memcpy(FlDis[FlCnt-1].Nm+6,"<Dir>",5);
       else CurrentSize+=FileInfo3.cbFile;
       if (FlDis[FlCnt-1].Atr&ATTR_SYSTEM){
          memset(FlDis[FlCnt-1].DisAtr,*Pink,1);
          memset(FlDis[FlCnt-1].DisAtr+1,*PinkReverse,1);
       }
       else if (FlDis[FlCnt-1].Atr&ATTR_HIDDEN){
          memset(FlDis[FlCnt-1].DisAtr,*Black,1);
          memset(FlDis[FlCnt-1].DisAtr+1,*BlackReverse,1);
       }
       else if (FlDis[FlCnt-1].Atr&ATTR_READONLY){
          memset(FlDis[FlCnt-1].DisAtr,*GreenBright,1);
          memset(FlDis[FlCnt-1].DisAtr+1,*GreenBrightReverse,1);
       }
       else if (FlDis[FlCnt-1].Atr&ATTR_DIR){
          memset(FlDis[FlCnt-1].DisAtr,*BlueBright,1);
          memset(FlDis[FlCnt-1].DisAtr+1,*BlueBrightReverse,1);
       }
       else {
          memset(FlDis[FlCnt-1].DisAtr,*WhiteBright,1);
          memset(FlDis[FlCnt-1].DisAtr+1,*WhiteBrightReverse,1);
       }
    }
 }

/**** SetupEditor ************************************************/
 void SetupEditor(void)
 {
    if (!memcmp(IniFileIn,"EditorName=",11)){ SEARCHINIFILEEND1
       memset(EditorName,0,sizeof(EditorName));
       memcpy(EditorName,IniFileIn+11,IniFileEnd-IniFileIn-11);
       EditorNameSet=1;
    }
    else if (!memcmp(IniFileIn,"EditSession=",12))
       if (IniFileIn[12]=='0') EditSession=0; else EditSession=1;
 }

/**** SetupExtention *********************************************/
 void SetupExtention(void)
 {
    SEARCHINIFILEEND2
    if ((!memcmp(IniFileIn,"SS1",3))||(!memcmp(IniFileIn,"ss1",3))) AssocSession[AssocCnt]=1;
    else if ((!memcmp(IniFileIn,"SS0",3))||(!memcmp(IniFileIn,"ss0",3))) AssocSession[AssocCnt]=0;
    else return;
    if (s=strchr(IniFileIn+4,'=')){
       memset(AssocExtention[AssocCnt],0,sizeof(AssocExtention[AssocCnt]));
       memset(AssocExtention[AssocCnt],'.',1);
       memcpy(AssocExtention[AssocCnt]+1,IniFileIn+4,s-IniFileIn-4);
    }
    else return;
    memset(AssocPgmName[AssocCnt],0,sizeof(AssocPgmName[AssocCnt]));
    memset(AssocParm[AssocCnt],0,sizeof(AssocParm[AssocCnt]));
    if (sx=strchr(s+1,' ')){
       memcpy(AssocPgmName[AssocCnt],s+1,sx-s-1);
       memcpy(AssocParm[AssocCnt],sx+1,IniFileEnd-s-1);
       if (s=strstr(AssocParm[AssocCnt],"&f")) memcpy(s,"&F",2);
    }
    else memcpy(AssocPgmName[AssocCnt],s+1,IniFileEnd-s-1);
    ++AssocCnt;
 }

/**** SetupGeneral ***********************************************/
 void SetupGeneral(void)
 {
    if (!memcmp(IniFileIn,"StartupDir=",11)&&!StartFl&&FirstDisp){ SEARCHINIFILEEND1
       memset(StartupDir,0,sizeof(StartupDir));
       memcpy(StartupDir,IniFileIn+11,IniFileEnd-IniFileIn-11);
       GoStartupDir();
    }
    else if (!memcmp(IniFileIn,"ExecSession=",12))
       if (IniFileIn[12]=='0') ExecSession=0; else ExecSession=1;
    else if (!memcmp(IniFileIn,"AlwaysSort=",11))
       if (IniFileIn[11]=='1') AlwaysSort=1; else AlwaysSort=0;
    else if (!memcmp(IniFileIn,"AutoClose=",10))
       if (IniFileIn[10]=='1') AutoClose=1; else AutoClose=0;
    else if (!memcmp(IniFileIn,"NoCloseIgnore=",14))
       if (IniFileIn[14]=='1') NoCloseIgnore=1; else NoCloseIgnore=0;
    else if (!memcmp(IniFileIn,"LogoTime=",9)){ SEARCHINIFILEEND1
       LogoTime=atoi(IniFileIn+9);
    }
    else if (!memcmp(IniFileIn,"WindowSize=",11)&&FirstDisp){ SEARCHINIFILEEND1
       i=sscanf(IniFileIn+11,"%d,%d",&ColMax,&RowMax);
       if (i==2){
        /*VioModeInfo.cb = sizeof(VioModeInfo);
          VioGetMode(&VioModeInfo,hvio );
          VioModeInfo.row=RowMax;
          VioModeInfo.col=ColMax;
          rc=VioSetMode(&VioModeInfo,hvio=0);*/
          memcpy(CmdParm,"mode co",7);
          memcpy(CmdParm+7,IniFileIn+11,strlen(IniFileIn+11)+1);
          rc=system(CmdParm);
       }
    }
 }

/**** SetWallColor ***********************************************/
 void SetWallColor(void)
 {
    VioWrtCharStrAtt(Title,ColMax,0,0,TitleAttr,hvio);
    VioWrtNAttr(BlueNull,(RowMax-2)*ColMax,1,0,hvio);
    VioWrtNAttr(MsgLineAttr,ColMax,RowMax-1,0,hvio);
    VioWrtNAttr(WallAttr,ColMax,3,0,hvio);
    VioWrtNChar("",ColMax,3,0,hvio);
    VioWrtCharStr(Footer,ColMax,RowMax-1,0,hvio);
    VioWrtCharStrAtt(FlMask,strlen(FlMask),2,70,WallAttr,hvio);
 }

/**** SetFullDirName *********************************************/
 void SetFullDirName(void)
 {
    memset(FulDirNm,0,sizeof(FulDirNm));
    memcpy(FulDirNm,DriveDis,1);
    memcpy(FulDirNm+(i=1),":",1);
    memcpy(FulDirNm+(i+=1),PathDis,(j=strlen(PathDis)));
    if(j-1) memcpy(FulDirNm+(i+=j),"\\",1);
 }

/**** SetFullFileName ********************************************/
 void SetFullFileName(void)
 {
    memcpy(FulFlNm,DriveDis,1);
    memcpy(FulFlNm+(i=1),":",1);
    memcpy(FulFlNm+(i+=1),PathDis,(j=strlen(PathDis)));
    if(j-1) memcpy(FulFlNm+(i+=j),"\\",1);
    memcpy(FulFlNm+(i+=1),FlDis[SelFl].Nm+29,strlen(FlDis[SelFl].Nm+29)+1);
 }

/**** ShowBottom *************************************************/
 void ShowBottom(void)
 {
    SelFl=FlCnt-1; PageNo=(FlCnt+(RowMax-6))/(RowMax-5);
    StartFl=(PageNo-1)*(RowMax-5);
    SaveRow=SelFl-StartFl+4;
    ShowType=0;ShowFileList();
 }

/**** ShowFileList ***********************************************/
 void ShowFileList(void)
 {
    VioWrtCharStrAtt(FlCntDis,FlCntDisLen,2,1,BlueBright,hvio);
    VioWrtCharStrAtt(MarkCntDis,MarkCntDisLen,2,20,BlueBright,hvio);
    switch(ShowType){
       case 0:
          VioSetCurPos(Row=SaveRow,0,hvio);
          break;
       case 1:
          SelFl=StartFl;
          VioSetCurPos(SaveRow=Row=4,0,hvio);
          break;
       case 2:
          --SelFl;
          VioSetCurPos(SaveRow=Row=RowMax-2,0,hvio);
          break;
    }
    for (i=4,j=StartFl;i<RowMax-1&&j<FlCnt;i++,j++)
       VioWrtCharStrAtt(FlDis[j].Nm,ColMax,i,0,FlDis[j].DisAtr+(j==SelFl),hvio);
    if (FlCnt-StartFl<RowMax-5){
       RestCell=((RowMax-5)-(FlCnt-StartFl))*ColMax;
       VioWrtNAttr(BlueNull,RestCell,(FlCnt-StartFl)+4,0,hvio);
       VioWrtNChar(" ",RestCell,(FlCnt-StartFl)+4,0,hvio);
    }
    memset(PageDis,0,sizeof(PageDis));
    PageNo=((SelFl+1)+(RowMax-6))/(RowMax-5);
    sprintf(PageDis,"Page:%u/%u",PageNo,(FlCnt+(RowMax-6))/(RowMax-5));
    VioWrtCharStrAtt(PageDis,PageDisLen,2,34,BlueBright,hvio);
 }

/**** ShowHelp1 ***************************************************/
 void ShowHelp1(void)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0], "  ★ＦｉｌｅＳｔａｒ★の使用説明　１／７                    ",60);
    memset(MsgTxt[1],0,60);
    memcpy(MsgTxt[2], "●ファイル一覧の  示／カー　ルの移動 (1/3)                  ",60);
    memcpy(MsgTxt[2]+16,Hyou,2);memcpy(MsgTxt[2]+26,So,2);
    memcpy(MsgTxt[3], "    ←↑           上ヘ移動します．                         ",60);
    memcpy(MsgTxt[4], "    ↓→           下ヘ移動します．                         ",60);
    memcpy(MsgTxt[5], "    PageUp         前ページヘ移動します．                   ",60);
    memcpy(MsgTxt[6], "    PageDown       次ページヘ移動します．                   ",60);
    memcpy(MsgTxt[7], "    －             ページ先頭ファイルへ移動します．         ",60);
    memcpy(MsgTxt[8], "    ＋             ページ最終ファイルへ移動します．         ",60);
    memcpy(MsgTxt[9], "    Home           先頭ファイルへ移動します．               ",60);
    memcpy(MsgTxt[10],"    End            最終ファイルへ移動します．               ",60);
    memset(MsgTxt[11],0,60);
    memcpy(MsgTxt[12],"           Down/PageDown:次トピック        Enter/Esc:戻る   ",60);
    MsgTxtLen[0]=60; MsgTxtLen[1]=60; MsgTxtLen[2]=60; MsgTxtLen[3]=60;
    MsgTxtLen[4]=60; MsgTxtLen[5]=60; MsgTxtLen[6]=60; MsgTxtLen[7]=60;
    MsgTxtLen[8]=60; MsgTxtLen[9]=60; MsgTxtLen[10]=60; MsgTxtLen[11]=60;
    MsgTxtLen[12]=60;  MsgTxtLen[13]=0;
    MSGBOXKBDINWHILE (KeyInfo.chChar!=ESC&&KeyInfo.chScan!=PAGE_DOWN&&KeyInfo.chScan!=ARROW_DOWN
                    &&KeyInfo.chChar!=ENTER);
    if (KeyInfo.chScan==PAGE_DOWN||KeyInfo.chScan==ARROW_DOWN) ShowHelp2();
    else MSGBOXCLEAR
 }

/**** ShowHelp2 **************************************************/
 void ShowHelp2(void)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0], "  ★ＦｉｌｅＳｔａｒ★の使用説明　２／７                    ",60);
    memset(MsgTxt[1],0,60);
    memcpy(MsgTxt[2], "●ファイル一覧の  示／カー　ルの移動 (2/3)                  ",60);
    memcpy(MsgTxt[2]+16,Hyou,2);memcpy(MsgTxt[2]+26,So,2);
    memset(MsgTxt[3],0,60);
    memcpy(MsgTxt[4], "    Enter          ディレクトリーの場合，中へ移動します．   ",60);
    memcpy(MsgTxt[5], "    BackSpace      親ディレクトリーへ移ります．             ",60);
    memcpy(MsgTxt[6], "    ￥             ルート・ディレクトリーへ移ります．       ",60);
    memset(MsgTxt[7],0,60);
    memcpy(MsgTxt[8], "    Ｌ             別のドライブへ移ります．                 ",60);
    memcpy(MsgTxt[9], "    １～９         ドライブＡ～Ｉへ移ります．               ",60);
    memset(MsgTxt[10],0,60);
    memcpy(MsgTxt[11],"           Up/PageUp    :前トピック                         ",60);
    memcpy(MsgTxt[12],"           Down/PageDown:次トピック        Enter/Esc:戻る   ",60);
    MsgTxtLen[0]=60; MsgTxtLen[1]=60; MsgTxtLen[2]=60; MsgTxtLen[3]=60;
    MsgTxtLen[4]=60; MsgTxtLen[5]=60; MsgTxtLen[6]=60; MsgTxtLen[7]=60;
    MsgTxtLen[8]=60; MsgTxtLen[9]=60; MsgTxtLen[10]=60; MsgTxtLen[11]=60;
    MsgTxtLen[12]=60;  MsgTxtLen[13]=0;
    MSGBOXKBDINWHILE (KeyInfo.chChar!=ESC&&KeyInfo.chScan!=PAGE_DOWN&&KeyInfo.chScan!=ARROW_DOWN
                    &&KeyInfo.chScan!=PAGE_UP&&KeyInfo.chScan!=ARROW_UP&&KeyInfo.chChar!=ENTER);
    if (KeyInfo.chScan==PAGE_UP||KeyInfo.chScan==ARROW_UP) ShowHelp1();
    else if (KeyInfo.chScan==PAGE_DOWN||KeyInfo.chScan==ARROW_DOWN) ShowHelp3();
    else MSGBOXCLEAR
 }

/**** ShowHelp3 **************************************************/
 void ShowHelp3(void)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0], "  ★ＦｉｌｅＳｔａｒ★の使用説明　３／７                    ",60);
    memset(MsgTxt[1],0,60);
    memcpy(MsgTxt[2], "●ファイル一覧の  示／カー　ルの移動 (3/3)                  ",60);
    memcpy(MsgTxt[2]+16,Hyou,2);memcpy(MsgTxt[2]+26,So,2);
    memset(MsgTxt[3],0,60);
    memcpy(MsgTxt[4], "    Space          ファイルのマーキングをします．           ",60);
    memcpy(MsgTxt[5], "    Insert         全ファイルのマークをＯＮ／ＯＦＦします． ",60);
    memcpy(MsgTxt[6], "    Delete         ファイル名の頭出しをします．             ",60);
    memset(MsgTxt[7],0,60);
    memcpy(MsgTxt[8], "    Ｑ             ＦｉｌｅＳｔａｒを終了します．           ",60);
    memcpy(MsgTxt[9], "    Ｗ             ウインドウ・サイズを変更します．         ",60);
    memset(MsgTxt[10],0,60);
    memcpy(MsgTxt[11],"           Up/PageUp    :前トピック                         ",60);
    memcpy(MsgTxt[12],"           Down/PageDown:次トピック        Enter/Esc:戻る   ",60);
    MsgTxtLen[0]=60; MsgTxtLen[1]=60; MsgTxtLen[2]=60; MsgTxtLen[3]=60;
    MsgTxtLen[4]=60; MsgTxtLen[5]=60; MsgTxtLen[6]=60; MsgTxtLen[7]=60;
    MsgTxtLen[8]=60; MsgTxtLen[9]=60; MsgTxtLen[10]=60; MsgTxtLen[11]=60;
    MsgTxtLen[12]=60;  MsgTxtLen[13]=0;
    MSGBOXKBDINWHILE (KeyInfo.chChar!=ESC&&KeyInfo.chScan!=PAGE_DOWN&&KeyInfo.chScan!=ARROW_DOWN
                    &&KeyInfo.chScan!=PAGE_UP&&KeyInfo.chScan!=ARROW_UP&&KeyInfo.chChar!=ENTER);
    if (KeyInfo.chScan==PAGE_UP||KeyInfo.chScan==ARROW_UP) ShowHelp2();
    else if (KeyInfo.chScan==PAGE_DOWN||KeyInfo.chScan==ARROW_DOWN) ShowHelp4();
    else MSGBOXCLEAR
 }

/**** ShowHelp4 **************************************************/
 void ShowHelp4(void)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0], "  ★ＦｉｌｅＳｔａｒ★の使用説明　４／７                    ",60);
    memset(MsgTxt[1],0,60);
    memcpy(MsgTxt[2], "●ファイルの基本操作 (1/2)                                  ",60);
    memcpy(MsgTxt[3], "    Ａ            ファイル属性の変更をします．              ",60);
    memcpy(MsgTxt[4], "    Ｃ　　　　　　ファイル／ディレクトリーをコピーします．  ",60);
    memcpy(MsgTxt[5], "    Ｄ            ファイル／ディレクトリーを削除します．    ",60);
    memcpy(MsgTxt[6], "    Ｅ            ファイルの編集をします．                  ",60);
    memcpy(MsgTxt[7], "    Ｆ            ファイルの検索をします．                  ",60);
    memcpy(MsgTxt[8], "    Ｊ            ディレクトリーのジャンプをします．        ",60);
    memcpy(MsgTxt[9], "    Ｋ            ディレクトリーを作成します．              ",60);
    memset(MsgTxt[10],0,60);
    memcpy(MsgTxt[11],"           Up/PageUp    :前トピック                         ",60);
    memcpy(MsgTxt[12],"           Down/PageDown:次トピック        Enter/Esc:戻る   ",60);
    MsgTxtLen[0]=60; MsgTxtLen[1]=60; MsgTxtLen[2]=60; MsgTxtLen[3]=60;
    MsgTxtLen[4]=60; MsgTxtLen[5]=60; MsgTxtLen[6]=60; MsgTxtLen[7]=60;
    MsgTxtLen[8]=60; MsgTxtLen[9]=60; MsgTxtLen[10]=60; MsgTxtLen[11]=60;
    MsgTxtLen[12]=60;  MsgTxtLen[13]=0;
    MSGBOXKBDINWHILE (KeyInfo.chChar!=ESC&&KeyInfo.chScan!=PAGE_DOWN&&KeyInfo.chScan!=ARROW_DOWN
                    &&KeyInfo.chScan!=PAGE_UP&&KeyInfo.chScan!=ARROW_UP&&KeyInfo.chChar!=ENTER);
    if (KeyInfo.chScan==PAGE_UP||KeyInfo.chScan==ARROW_UP) ShowHelp3();
    else if (KeyInfo.chScan==PAGE_DOWN||KeyInfo.chScan==ARROW_DOWN) ShowHelp5();
    else MSGBOXCLEAR
 }

/**** ShowHelp5 **************************************************/
 void ShowHelp5(void)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0], "  ★ＦｉｌｅＳｔａｒ★の使用説明　５／７                    ",60);
    memset(MsgTxt[1],0,60);
    memcpy(MsgTxt[2], "●ファイルの基本操作 (2/2)                                  ",60);
    memcpy(MsgTxt[3], "    Ｍ          　ファイル／ディレクトリーを移動します．    ",60);
    memcpy(MsgTxt[4], "    Ｎ            ファイル／ディレクトリーを改名します．    ",60);
    memcpy(MsgTxt[5], "    Ｏ            ＸＣＯＰＹコマンドを呼び出します．        ",60);
    memcpy(MsgTxt[6], "    Ｓ            ファイルの  ートをします．                ",60);
    memcpy(MsgTxt[6]+28,So,2);
    memcpy(MsgTxt[7], "    Ｖ            ファイルの  示をします．                  ",60);
    memcpy(MsgTxt[7]+28,Hyou,2);
    memcpy(MsgTxt[8], "    Ｙ            ファイル・マスク文字(ﾜｲﾙﾄﾞ･ｶｰﾄﾞ)を        ",60);
    memcpy(MsgTxt[9], "                  変更します.                               ",60);
    memset(MsgTxt[10],0,60);
    memcpy(MsgTxt[11],"           Up/PageUp    :前トピック                         ",60);
    memcpy(MsgTxt[12],"           Down/PageDown:次トピック        Enter/Esc:戻る   ",60);
    MsgTxtLen[0]=60; MsgTxtLen[1]=60; MsgTxtLen[2]=60; MsgTxtLen[3]=60;
    MsgTxtLen[4]=60; MsgTxtLen[5]=60; MsgTxtLen[6]=60; MsgTxtLen[7]=60;
    MsgTxtLen[8]=60; MsgTxtLen[9]=60; MsgTxtLen[10]=60; MsgTxtLen[11]=60;
    MsgTxtLen[12]=60;  MsgTxtLen[13]=0;
    MSGBOXKBDINWHILE (KeyInfo.chChar!=ESC&&KeyInfo.chScan!=PAGE_DOWN&&KeyInfo.chScan!=ARROW_DOWN
                    &&KeyInfo.chScan!=PAGE_UP&&KeyInfo.chScan!=ARROW_UP&&KeyInfo.chChar!=ENTER);
    if (KeyInfo.chScan==PAGE_UP||KeyInfo.chScan==ARROW_UP) ShowHelp4();
    else if (KeyInfo.chScan==PAGE_DOWN||KeyInfo.chScan==ARROW_DOWN) ShowHelp6();
    else MSGBOXCLEAR
 }

/**** ShowHelp6 **************************************************/
 void ShowHelp6(void)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0], "  ★ＦｉｌｅＳｔａｒ★の使用説明　６／７                    ",60);
    memset(MsgTxt[1],0,60);
    memcpy(MsgTxt[2], "●ファイルのＷＰＳシェル操作                                ",60);
    memcpy(MsgTxt[3], "    Ｅｎｔｅｒ                                              ",60);
    memcpy(MsgTxt[4], "    .exe.cmd.com     プログラムを実行します．               ",60);
    memcpy(MsgTxt[5], "    .inf             ＩＮＦファイルを  示します．           ",60);
    memcpy(MsgTxt[5]+37,Hyou,2);
    memcpy(MsgTxt[6], "     その他          ファイル内容の  示をします．           ",60);
    memcpy(MsgTxt[6]+35,Hyou,2);
    memcpy(MsgTxt[7], "    Ｉ               デスクトップにアイコンを登録します.    ",60);
    memcpy(MsgTxt[8], "    Ｘ               コマンドを実行します．                 ",60);
    memcpy(MsgTxt[9], "    ．               コマンド・プロセッサーを起動します.    ",60);
    memset(MsgTxt[10],0,60);
    memcpy(MsgTxt[11],"           Up/PageUp    :前トピック                         ",60);
    memcpy(MsgTxt[12],"           Down/PageDown:次トピック        Enter/Esc:戻る   ",60);
    MsgTxtLen[0]=60; MsgTxtLen[1]=60; MsgTxtLen[2]=60; MsgTxtLen[3]=60;
    MsgTxtLen[4]=60; MsgTxtLen[5]=60; MsgTxtLen[6]=60; MsgTxtLen[7]=60;
    MsgTxtLen[8]=60; MsgTxtLen[9]=60; MsgTxtLen[10]=60; MsgTxtLen[11]=60;
    MsgTxtLen[12]=60;  MsgTxtLen[13]=0;
    MSGBOXKBDINWHILE (KeyInfo.chChar!=ESC&&KeyInfo.chScan!=PAGE_DOWN&&KeyInfo.chScan!=ARROW_DOWN
                    &&KeyInfo.chScan!=PAGE_UP&&KeyInfo.chScan!=ARROW_UP&&KeyInfo.chChar!=ENTER);
    if (KeyInfo.chScan==PAGE_UP||KeyInfo.chScan==ARROW_UP) ShowHelp5();
    else if (KeyInfo.chScan==PAGE_DOWN||KeyInfo.chScan==ARROW_DOWN) ShowHelp7();
    else MSGBOXCLEAR
 }

/**** ShowHelp7 **************************************************/
 void ShowHelp7(void)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0], "  ★ＦｉｌｅＳｔａｒ★の使用説明　７／７                    ",60);
    memset(MsgTxt[1],0,60);
    memcpy(MsgTxt[2], "●ＰＦキーの機                                              ",60);
    memcpy(MsgTxt[2]+14,Noh,2);
    memset(MsgTxt[3],0,60);
    memcpy(MsgTxt[4], "    ＰＦ１        説明ウインドウを  示します．              ",60);
    memcpy(MsgTxt[4]+34,Hyou,2);
    memcpy(MsgTxt[5], "    ＰＦ２        カスタマイズの一時変更をします．          ",60);
    memcpy(MsgTxt[6], "    ＰＦ３        ＦｉｌｅＳｔａｒを終了します．            ",60);
    memcpy(MsgTxt[7], "    ＰＦ４        マクロの実行をします．                    ",60);
    memcpy(MsgTxt[8], "                                                            ",60);
    memcpy(MsgTxt[9], "    ＰＦ１２      シアターを  示します．                    ",60);
    memcpy(MsgTxt[9]+28,Hyou,2);
    memset(MsgTxt[10],0,60);
    memset(MsgTxt[11],0,60);
    memcpy(MsgTxt[12],"                       Up/PageUp    :前トピック  Esc:戻る   ",60);
    MsgTxtLen[0]=60; MsgTxtLen[1]=60; MsgTxtLen[2]=60; MsgTxtLen[3]=60;
    MsgTxtLen[4]=60; MsgTxtLen[5]=60; MsgTxtLen[6]=60; MsgTxtLen[7]=60;
    MsgTxtLen[8]=60; MsgTxtLen[9]=60; MsgTxtLen[10]=60; MsgTxtLen[11]=60;
    MsgTxtLen[12]=60;  MsgTxtLen[13]=0;
    MSGBOXKBDINWHILE (KeyInfo.chChar!=ESC&&KeyInfo.chScan!=PAGE_UP&&KeyInfo.chScan!=ARROW_UP
                    &&KeyInfo.chChar!=ENTER);
    if (KeyInfo.chScan==PAGE_UP||KeyInfo.chScan==ARROW_UP) ShowHelp6();
    else MSGBOXCLEAR
 }

/**** ShowMsgBox *************************************************/
 void ShowMsgBox(void)
 {
    SaveRow=Row;
    for (i=BoxWide=0;MsgTxtLen[i];i++)
       if (MsgTxtLen[i]>BoxWide) BoxWide=MsgTxtLen[i];
    if (BoxWide+7<ColMax) BoxWide+=6;
    else BoxWide=ColMax;
    if (i+10<RowMax) BoxHigh=i+4;
    else BoxHigh=RowMax-6;
    BoxTop=(RowMax-BoxHigh)/2+1;
    BoxLeft=(ColMax-BoxWide)/2;
    for (i=0;i<BoxHigh;i++){
       VioWrtNAttr(GrayNull,BoxWide,BoxTop+i,BoxLeft,hvio);
       VioWrtNChar (" ",BoxWide,BoxTop+i,BoxLeft,hvio);
    }
    VioWrtNAttr(BoxLineAttr,BoxWide,BoxTop,BoxLeft,hvio);
    VioWrtNChar ("",BoxWide,BoxTop,BoxLeft,hvio);
    VioWrtNAttr(BoxLineAttr,BoxWide,BoxTop+BoxHigh-1,BoxLeft,hvio);
    VioWrtNChar ("",BoxWide,BoxTop+BoxHigh-1,BoxLeft,hvio);
    for (i=0;MsgTxtLen[i];i++){
       if (MsgTxtLen[i]+3>BoxWide) j=BoxWide-3; else j=MsgTxtLen[i];
       if (i<BoxHigh-4) VioWrtCharStrAtt(MsgTxt[i],j,BoxTop+2+i,BoxLeft+3,BoxLineAttr,hvio);
    }
    VioSetCurPos (BoxTop+1+i,BoxLeft+3+MsgTxtLen[i-1]+2,hvio);
 }

/**** ShowMsgBoxNull *********************************************/
 void ShowMsgBoxNull(void)
 {
    for (i=0;i<BoxHigh;i++){
       VioWrtNAttr(BlueNull,BoxWide,BoxTop+i,BoxLeft,hvio);
       VioWrtNChar (" ",BoxWide,BoxTop+i,BoxLeft,hvio);
    }
 }

/**** ShowMsgCopyOk ***********************************************/
 void ShowMsgCopyOk(void)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0],"ファイルのコピーが",18);
    memcpy(MsgTxt[1],"  完了しました    ",18);
    MsgTxtLen[0]=18; MsgTxtLen[1]=18; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgCopyStop *********************************************/
 void ShowMsgCopyStop(void)
 {
    MSGBOXCLEAR
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"ファイルのコピーが",18);
    memcpy(MsgTxt[1],"  中止されました  ",18);
    MsgTxtLen[0]=18; MsgTxtLen[1]=18; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgCrcErr ***********************************************/
 void ShowMsgCrcErr(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"データＣＲＣエラーです",22);
    MsgTxtLen[0]=22; MsgTxtLen[1]=0;
    MSGBOXDISP
 }

/**** ShowMsgCreateDirErr *****************************************/
 void ShowMsgCreateDirErr(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"ディレクトリーの作成ができません      ",38);
    memcpy(MsgTxt[1],"書込禁止/同一名がないか確認して下さい ",38);
    MsgTxtLen[0]=38; MsgTxtLen[1]=38; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgDeleteErr ********************************************/
 void ShowMsgDeleteErr(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"ﾌｧｲﾙ/ﾃﾞｨﾚｸﾄﾘｰのｺﾋﾟｰ/削除ができません   ",40);
    memcpy(MsgTxt[1],"他のﾌﾟﾛｾｽで参照中でないか確認して下さい",40);
    MsgTxtLen[0]=40; MsgTxtLen[1]=40; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgDeleteDeny *******************************************/
 void ShowMsgDeleteDeny(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"ﾌｧｲﾙの削除ができません    ",26);
    memcpy(MsgTxt[1],"書込み禁止か確認して下さい",26);
    MsgTxtLen[0]=26; MsgTxtLen[1]=26; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgDeleteStop *******************************************/
 void ShowMsgDeleteStop(void)
 {
    MSGBOXCLEAR
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"ファイルの削除が",16);
    memcpy(MsgTxt[1]," 中止されました ",16);
    MsgTxtLen[0]=16; MsgTxtLen[1]=16; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgDiskFull *********************************************/
 void ShowMsgDiskFull(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"ディスクが一杯です",18);
    MsgTxtLen[0]=18; MsgTxtLen[1]=0;
    MSGBOXDISP
 }

/**** ShowMsgDriveErr *********************************************/
 void ShowMsgDriveErr(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"  そのドライブは  ",18);
    memcpy(MsgTxt[1],"接続されていません",18);
    MsgTxtLen[0]=18; MsgTxtLen[1]=18; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgDriveNotReady ****************************************/
 void ShowMsgDriveNotReady(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"ドライブが未装着です",20);
    MsgTxtLen[0]=20; MsgTxtLen[1]=0;
    MSGBOXDISP
 }

/**** ShowMsgErr **************************************************/
 void ShowMsgErr(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"エラーが発生しました",20);
    memcpy(MsgTxt[1]," RC:                ",20);
    sprintf(MsgTxt[1]+4,"%04d",rc);
    MsgTxtLen[0]=20; MsgTxtLen[1]=20; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgExecErr **********************************************/
 void ShowMsgExecErr(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"プログラムの実行でエラーが発生しました",38);
    memcpy(MsgTxt[1],"リターンコード:                       ",38);
    memcpy(MsgTxt[2],"Msg:                                  ",38);
    sprintf(MsgTxt[1]+16,"%04d",rc);
    memcpy(MsgTxt[2]+4,StartData.ObjectBuffer,strlen(StartData.ObjectBuffer));
    MsgTxtLen[0]=38; MsgTxtLen[1]=38; MsgTxtLen[2]=38; MsgTxtLen[3]=0;
    MSGBOXDISP
 }

/**** ShowMsgExecNotF *********************************************/
 void ShowMsgExecNotF(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"プログラムの実行でエラーが発生しました",38);
    memcpy(MsgTxt[1],"以下のファイルが見つかりません　　　　",38);
    memcpy(MsgTxt[2],"Meg:                                  ",38);
    memcpy(MsgTxt[2]+4,StartData.ObjectBuffer,strlen(StartData.ObjectBuffer));
    MsgTxtLen[0]=38; MsgTxtLen[1]=38; MsgTxtLen[2]=38; MsgTxtLen[3]=0;
    MSGBOXDISP
 }

/**** ShowMsgExecOk ***********************************************/
 void ShowMsgExecOk(void)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0],"プログラムの実行に",18);
    memcpy(MsgTxt[1],"  成功しました    ",18);
    MsgTxtLen[0]=18; MsgTxtLen[1]=18; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgFindStop *********************************************/
 void ShowMsgFindStop(void)
 {
    MSGBOXCLEAR
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"ファイルの検索が",16);
    memcpy(MsgTxt[1]," 中止されました ",16);
    MsgTxtLen[0]=16; MsgTxtLen[1]=16; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgFormatErr ********************************************/
 void ShowMsgFormatErr(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"ﾄﾞﾗｲﾌﾞのﾌｫｰﾏｯﾄが",16);
    memcpy(MsgTxt[1]," 認識できません ",16);
    MsgTxtLen[0]=16; MsgTxtLen[1]=16; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgIconNa ***********************************************/
 void ShowMsgIconNa(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"アイコン登録をサポートしているのは",34);
    memcpy(MsgTxt[1],".exe .cmd .com .bat .infのみです．",34);
    MsgTxtLen[0]=34; MsgTxtLen[1]=34; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgIconErr ***********************************************/
 void ShowMsgIconErr(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"エラ－が発生しアイコンは登録されませんでした",44);
    memcpy(MsgTxt[1],"同じ名前のアイコンがないか確認して下さい    ",44);
    MsgTxtLen[0]=44; MsgTxtLen[1]=44; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgIconOk ************************************************/
 void ShowMsgIconOk(void)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0],"デスクトップにアイコンが",24);
    memcpy(MsgTxt[1],"    登録されました      ",24);
    MsgTxtLen[0]=24; MsgTxtLen[1]=24; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgIconReg ***********************************************/
 void ShowMsgIconReg(void)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0],"アイコンの登録中です",24);
    memset(MsgTxt[1],0,sizeof(MsgTxt[0]));
    MsgTxtLen[0]=24; MsgTxtLen[1]=24; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgJunpDirErr ********************************************/
 void ShowMsgJunpDirErr(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"登録できるのは１～５の行です",28);
    MsgTxtLen[0]=28; MsgTxtLen[1]=0;
    MSGBOXDISP
 }

/**** ShowMsgLocked **********************************************/
 void ShowMsgLocked(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"ﾄﾞﾗｲﾌﾞが他のﾌﾟﾛｾｽでﾛｯｸされています",34);
    MsgTxtLen[0]=34; MsgTxtLen[1]=0;
    MSGBOXDISP
 }

/**** ShowMsgMoveStop ********************************************/
 void ShowMsgMoveStop(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"ファイルの移動が",16);
    memcpy(MsgTxt[1]," 中止されました ",16);
    MsgTxtLen[0]=16; MsgTxtLen[1]=16; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgNameErr *********************************************/
 void ShowMsgNameErr(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"新しい名前への変更ができません　　    ",38);
    memcpy(MsgTxt[1],"同一名のファイルがないか確認して下さい",38);
    memcpy(MsgTxt[2],"他のプロセスで参照中の可　性もあります",38);
    memcpy(MsgTxt[2]+24,Noh,2);
    MsgTxtLen[0]=38; MsgTxtLen[1]=38; MsgTxtLen[2]=38; MsgTxtLen[3]=0;
    MSGBOXDISP
 }

/**** ShowMsgNameLong ********************************************/
 void ShowMsgNameLong(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"名前が長過ぎます",16);
    MsgTxtLen[0]=16; MsgTxtLen[1]=0;
    MSGBOXDISP
 }

/**** ShowMsgNameNg **********************************************/
 void ShowMsgNameNg(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"指定が無効です",14);
    MsgTxtLen[0]=14; MsgTxtLen[1]=0;
    MSGBOXDISP
 }

/**** ShowMsgNotFound *********************************************/
 void ShowMsgNotFound(void)
 {
    MSGBOXCLEAR
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"そのファイルは見つかりません",28);
    MsgTxtLen[0]=28; MsgTxtLen[1]=0;
    MSGBOXDISP
 }

/**** ShowMsgOpenErr *********************************************/
 void ShowMsgOpenErr(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"ファイルがオープンできません",28);
    MsgTxtLen[0]=28; MsgTxtLen[1]=0;
    MSGBOXDISP
 }

/**** ShowMsgParmDirErr ******************************************/
 void ShowMsgParmDirErr(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"ﾊﾟﾗﾒｰﾀ指定ディレクトリーへ",26);
    memcpy(MsgTxt[0]+6,Hyou,2);
    memcpy(MsgTxt[1],"   移動できませんでした   ",26);
    MsgTxtLen[0]=26; MsgTxtLen[1]=26; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgPassNg **********************************************/
 void ShowMsgPassNg(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"その名前はﾌｧｲﾙとして存在しています",34);
    memcpy(MsgTxt[1],"ﾃﾞｨﾚｸﾄﾘｰの作成/ｺﾋﾟｰはできません   ",34);
    memset(MsgTxt[2],0,sizeof(MsgTxt[2]));
    strcpy(MsgTxt[2]+2,StartData.ObjectBuffer);
    MsgTxtLen[0]=34; MsgTxtLen[1]=34; MsgTxtLen[2]=34; MsgTxtLen[3]=0;
    MSGBOXDISP
 }

/**** ShowMsgPassNo **********************************************/
 void ShowMsgPassNo(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"ﾃﾞｨﾚｸﾄﾘｰが見つかりません",24);
    MsgTxtLen[0]=24; MsgTxtLen[1]=0;
    MSGBOXDISP
 }

/**** ShowMsgSameDir *********************************************/
 void ShowMsgSameDir(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"同一ﾃﾞｨﾚｸﾄﾘｰへの     ",22);
    memcpy(MsgTxt[1],"ｺﾋﾟｰ/移動はできません",22);
    MsgTxtLen[0]=22; MsgTxtLen[1]=22; MsgTxtLen[2]=0;
    memcpy(MsgTxt[2]+1,InpLine,strlen(InpLine));
    MSGBOXDISP
 }

/**** ShowMsgSameName ********************************************/
 void ShowMsgSameName(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"同一名が存在します",18);
    MsgTxtLen[0]=18; MsgTxtLen[1]=0;
    MSGBOXDISP
 }

/**** ShowMsgSectorNotFound **************************************/
 void ShowMsgSectorNotFound(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"セクターが見つかりません",24);
    MsgTxtLen[0]=24; MsgTxtLen[1]=0;
    MSGBOXDISP
 }

/**** ShowMsgSharedErr *******************************************/
 void ShowMsgSharedErr(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"他のﾌﾟﾛｾｽで使用中のため",23);
    memcpy(MsgTxt[1],"ｺﾋﾟｰ/削除はできません  ",23);
    memcpy(MsgTxt[2],"                       ",23);
    MsgTxtLen[0]=23; MsgTxtLen[1]=23; MsgTxtLen[2]=23; MsgTxtLen[3]=0;
    memcpy(MsgTxt[2]+1,InpLine,strlen(InpLine));
    MSGBOXDISP
 }

/**** ShowMsgStartUpDirErr ***************************************/
 void ShowMsgStartUpDirErr(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"起動時  示ディレクトリーへ",26);
    memcpy(MsgTxt[0]+6,Hyou,2);
    memcpy(MsgTxt[1],"   移動できませんでした   ",26);
    MsgTxtLen[0]=26; MsgTxtLen[1]=26; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowMsgWriteProtect ****************************************/
 void ShowMsgWriteProtect(void)
 {
    BoxLineAttr=GrayYellow;
    memcpy(MsgTxt[0],"書き込み禁止です",26);
    memcpy(MsgTxt[1],"                ",26);
    MsgTxtLen[0]=16; MsgTxtLen[1]=16; MsgTxtLen[2]=0;
    memcpy(MsgTxt[1]+1,InpLine,strlen(InpLine));
    MSGBOXDISP
 }

/**** ShowNewDrive ***********************************************/
 void ShowNewDrive(void)
 {
    QDrive();
    QDir();
    QFile();
    SelFl=StartFl=0;
    ShowType=1;ShowFileList();
    if (StartupDirErr==ERROR_NOT_DOS_DISK) ShowMsgFormatErr();
    VioSetCurPos(4,0,hvio);
 }

/**** ShowSummarySize *********************************************/
 void ShowSummarySize(void)
 {
    BoxLineAttr=GrayGreen;
    memset(MsgTxt[0],0,38);
    memcpy(MsgTxt[1],"サイズ合計:                           ",38);
    strcpy(MsgTxt[0],FlDis[SelFl].Nm+29);
    sprintf(MsgTxt[1]+26,"%u",FlSize);
    MsgTxtLen[0]=38; MsgTxtLen[1]=38; MsgTxtLen[2]=0;
    MSGBOXDISP
 }

/**** ShowTitleWindow ********************************************/
 void ShowTitleWindow(void)
 {
    VioGetCurType(&CursorInfo,hvio);
    CursorInfo.attr=-1;VioSetCurType(&CursorInfo,hvio);
    if (!LogoTime) return;
    puts(BLUE);puts(CLEAR);
    BoxWide=(ColMax>70 ? 66:ColMax-4);
    BoxHigh=(RowMax>18 ? 16:RowMax-2);
    BoxTop=(RowMax-BoxHigh)/2;
    BoxLeft=(ColMax-BoxWide)/2;
    for (i=0;i<BoxHigh-1;i++){
       if (i<4)       VioWrtCharStrAtt(TitleLogo[i],BoxWide,BoxTop+i,BoxLeft,"\x0B",hvio);
       else if (i<8)  VioWrtCharStrAtt(TitleLogo[i],BoxWide,BoxTop+i,BoxLeft,"\x1B",hvio);
       else if (i<12) VioWrtCharStrAtt(TitleLogo[i],BoxWide,BoxTop+i,BoxLeft,"\x9B",hvio);
       else           VioWrtCharStrAtt(TitleLogo[i],BoxWide,BoxTop+i,BoxLeft,"\x3B",hvio);
    }
    VioWrtCharStrAtt(TitleLogo[BoxHigh-1],BoxWide,BoxTop+i,BoxLeft,"\x3B",hvio);
    for (i=0;i< 20*LogoTime;i++) VioWrtCharStrAtt(TitleLogo[1]+4,2,BoxTop+1,BoxLeft+4,"\x0B",hvio);
    for (i=0;i< 20*LogoTime;i++) VioWrtCharStrAtt(TitleLogo[1]+4,2,BoxTop+1,BoxLeft+4,"\x0E",hvio);
    for (i=0;i<  1*LogoTime;i++) VioWrtCharStrAtt(TitleLogo[1]+4,2,BoxTop+1,BoxLeft+4,"\x0A",hvio);
    for (i=0;i< 20*LogoTime;i++) VioWrtCharStrAtt(TitleLogo[3]+17,2,BoxTop+3,BoxLeft+17,"\x0E",hvio);
    for (i=0;i<  1*LogoTime;i++) VioWrtCharStrAtt(TitleLogo[3]+17,2,BoxTop+3,BoxLeft+17,"\x0E",hvio);
    for (i=0;i< 20*LogoTime;i++) VioWrtCharStrAtt(TitleLogo[1]+32,2,BoxTop+1,BoxLeft+32,"\x0E",hvio);
    for (i=0;i<  1*LogoTime;i++) VioWrtCharStrAtt(TitleLogo[1]+32,2,BoxTop+1,BoxLeft+32,"\x0A",hvio);
    for (i=0;i< 20*LogoTime;i++) VioWrtCharStrAtt(TitleLogo[5]+43,2,BoxTop+5,BoxLeft+43,"\x1E",hvio);
    for (i=0;i<  1*LogoTime;i++) VioWrtCharStrAtt(TitleLogo[5]+43,2,BoxTop+5,BoxLeft+43,"\x1D",hvio);
    for (i=0;i< 20*LogoTime;i++) VioWrtCharStrAtt(TitleLogo[5]+49,2,BoxTop+5,BoxLeft+49,"\x1B",hvio);
    for (i=0;i<  1*LogoTime;i++) VioWrtCharStrAtt(TitleLogo[5]+49,2,BoxTop+5,BoxLeft+49,"\x1A",hvio);
    for (i=0;i< 20*LogoTime;i++) VioWrtCharStrAtt(TitleLogo[5]+61,2,BoxTop+5,BoxLeft+61,"\x1E",hvio);
    for (i=0;i< 60*LogoTime;i++) VioWrtCharStrAtt(TitleLogo[5]+61,2,BoxTop+5,BoxLeft+61,"\x1E",hvio);
 }

/**** SummarySize *********************************************/
 void SummarySize(PSZ DirNm)
 {
    int ia;
    DosSetCurrentDir(DirNm);
    PathLen=124;DosQueryCurrentDir(0,PathDis+1,&PathLen);
    strcpy(FlMask,"*.*"); QFile();
    for (ia=1;ia<FlCnt&&KeyInfo.chChar!=ESC;++ia){
       OpMode=atol(FlDis[ia].Nm);
       FlSize=FlSize+OpMode;
       SelFl=ia;SetFullFileName();SummarySizeDisp(FulFlNm,FlSize);
       KbdCharIn(&KeyInfo,IO_NOWAIT,0);
       if (FlDis[ia].Atr&ATTR_DIR) SummarySize(FlDis[ia].Nm+29);
    }
    DosSetCurrentDir("..");QFile();
    PathLen=124;DosQueryCurrentDir(0,PathDis+1,&PathLen);
 }
/**** SummarySizeDisp *******************************************/
 void SummarySizeDisp(PSZ FlNm,ULONG Size)
 {
    BoxLineAttr=GrayGreen;
    memcpy(MsgTxt[0],"サイズ合計の計算中:                   ",38);
    memset(MsgTxt[1],0,38);
    sprintf(MsgTxt[0]+26,"%u",Size);
    memcpy(MsgTxt[1]+1,FlNm,strlen(FlNm));
    MsgTxtLen[0]=38; MsgTxtLen[1]=38; MsgTxtLen[2]=0;
    if (FirstDisp) {ShowMsgBox();FirstDisp=0;}
    else if (1<BoxHigh-4){
       VioWrtCharStrAtt(MsgTxt[0]+26,BoxWide-6-26,BoxTop+2,BoxLeft+3+26,BoxLineAttr,hvio);
       VioWrtCharStrAtt(MsgTxt[1],BoxWide-6,BoxTop+3,BoxLeft+3,BoxLineAttr,hvio);
    }
 }

/**** ViewFile ***************************************************/
 void ViewFile(void)
 {
int jx=0;
    sscanf(FlDis[SelFl].Nm,"%d",&FlSize);
    Fl=fopen(FlDis[SelFl].Nm+29,"rb");
    if (Fl==NULL) {ShowMsgOpenErr();return;}
    memcpy(ViewFlTitle+18,Hyou,2);memset(ViewFlTitle+27,0,sizeof(ViewFlTitle)-27);
    memcpy(ViewFlTitle+27,FlDis[SelFl].Nm+29,strlen(FlDis[SelFl].Nm+29));
    VioWrtCharStrAtt(ViewFlTitle,ColMax,0,0,AtrViewFlTitle,hvio);
    VioWrtNAttr(AtrViewFlNull,(RowMax-1)*ColMax,1,0,hvio);

    BufNo=0; BufLines[0]=BufLines[1]=0; FlPos[0]=FlPos[1]=0;
    Rest=fread(FlBuff[0],1,FlBuffLen,Fl);if (Rest<FlBuffLen) FlEnd=1; else FlEnd=0;
    pStart=FlBuff[BufNo];
    LineEnd=0; LineSeq=1; FirstBuf=FirstLine=FirstSet=LastBuf=LastLine=LastSet=0;
    ViewFileNew();
sx="00";
    do{

/*VioSetCurPos (0,0,hvio);
printf("%s Lines: %d %d Buf: %d(%d,%d) First: %d %d %d Last: %d %d %d Rest: %d  LineSeq: %d       \n",
sx,BufLines[0],BufLines[1],BufNo,FlPos[0],FlPos[1],FirstSet,FirstBuf,FirstLine,
LastSet,LastBuf,LastLine,Rest,LineSeq);*/

       KbdCharIn(&KeyInfo,IO_WAIT,0);
       KEY: switch(KeyInfo.chScan){
          case ARROW_UP:
             if (FirstSet)
                if (!FirstLine&&!FlPos[FirstBuf]) break;
                else if (FirstLine){
                   --FirstLine;
                   VioScrollDn(1,0,RowMax-1,ColMax-1,1," \x00",hvio);
                   pStart=BufPos[FirstBuf][FirstLine]; LineSeq=1; ViewFileLine();
                }
                /*FirstBufが最新で別ﾊﾞｯﾌｧにLineあり*/
                else if (FirstBuf==BufNo&&BufLines[FirstBuf?0:1]) {
                   FirstBuf=BufNo?0:1; FirstLine=BufLines[FirstBuf]-1;
                   VioScrollDn(1,0,RowMax-1,ColMax-1,1," \x00",hvio);
                   pStart=BufPos[FirstBuf][FirstLine]; LineSeq=1; ViewFileLine();
                }
                /*FirstBufでないﾊﾞｯﾌｧが最新でFirstBuf残りなし*/
                else {BufNo=FirstBuf; LineSeq=1; ViewFileRewind(); goto KEY;}
             else if (LastSet){
                BufNo=LastBuf; LineSeq=RowMax-2-LastLine; ViewFileRewind();
                FirstBuf=BufNo?0:1; FirstLine=ix; FirstSet=1; goto KEY;
             }
             if (BufLines[FirstBuf]-FirstLine>RowMax-2) {
                LastBuf=FirstBuf; LastLine=FirstLine+RowMax-2; LastSet=1;
             }
             else if (FirstBuf!=BufNo
                   &&(BufLines[FirstBuf]-FirstLine)+BufLines[BufNo]>RowMax-2){
                LastBuf=BufNo; LastLine=RowMax-2-(BufLines[FirstBuf]-FirstLine); LastSet=1;
             }
             else LastSet=0;
             break;
          case ARROW_DOWN:
             if (FlEnd&&!LastSet) break;
             if (LastSet)
                /*LastBufﾊﾞｯﾌｧ上に残ﾗｲﾝあり*/
                if (LastLine<BufLines[LastBuf]-1){
                   VioScrollUp(1,0,RowMax-1,ColMax-1,1," \x00",hvio);
                   pStart=BufPos[LastBuf][++LastLine]; LineSeq=RowMax-1; ViewFileLine();
                }
                /*LastBufﾊﾞｯﾌｧ上に残ﾗｲﾝなし,別ﾊﾞｯﾌｧが最新かつ一度表示されたﾊﾞｯﾌｧ*/
                else if (LastBuf!=BufNo&&BufLines[BufNo]){
                   LastBuf=BufNo; pStart=BufPos[LastBuf][LastLine=0];
                   VioScrollUp(1,0,RowMax-1,ColMax-1,1," \x00",hvio);
                   LineSeq=RowMax-1; ViewFileLine();
                }
                /*残ﾗｲﾝなし*/
                else if (FlSize-FlPos[BufNo]>=FlBuffLen||Rest) {
                   pStart=BufPos[BufNo][BufLines[BufNo]];
                   if (!Rest) Rest=FlBuff[BufNo]+FlBuffLen-pStart;
                   VioScrollUp(1,0,RowMax-1,ColMax-1,1," \x00",hvio);
                   LineSeq=RowMax-1; ViewFileNew();
                }
                else break;
             else if (FirstSet){
                pStart=BufPos[BufNo][BufLines[BufNo]];
                if (!Rest) Rest=(FlBuff[BufNo]+FlBuffLen)-pStart;
                if (FirstBuf==BufNo) LineSeq=BufLines[BufNo]-FirstLine+1;
                else LineSeq=BufLines[FirstBuf]-FirstLine+BufLines[BufNo]+1;
                ViewFileNew(); goto KEY;
             }
             if (LastLine>=RowMax-2) {
                FirstBuf=LastBuf; FirstLine=LastLine-(RowMax-2); FirstSet=1;
             }
             else if (LastLine+1+BufLines[LastBuf?0:1]>RowMax-1){
                FirstBuf=LastBuf?0:1; FirstLine=BufLines[FirstBuf]-(RowMax-LastLine-2);
                FirstSet=1;
             }
             else FirstSet=0;
             break;
          case PAGE_UP:
             if (!FirstLine&&!FlPos[FirstBuf]) break;
             if (FirstSet){
                if (FirstLine>RowMax-2) {FirstLine-=RowMax-1; ViewFilePage();}
                else if (FirstBuf==BufNo&&FirstLine+BufLines[BufNo?0:1]>RowMax-2){
                   FirstBuf=BufNo?0:1; FirstLine+=BufLines[FirstBuf]-(RowMax-1);
                   ViewFilePage();
                }
                else {
                   BufNo=BufNo?0:1; LineSeq=RowMax-1-FirstLine; ViewFileRewind();
                   if (LineSeq) {FirstBuf=BufNo; FirstLine=0; FirstSet=1;}
                   else  {FirstBuf=BufNo?0:1; FirstLine=ix; FirstSet=1;}
                   ViewFilePage();
                }
             }
             else if (LastSet){
                BufNo=LastBuf; LineSeq=RowMax-2-LastLine; ViewFileRewind();
                FirstBuf=BufNo?0:1; FirstLine=ix; FirstSet=1; 
                goto KEY;
             }
             break;
          case PAGE_DOWN:
             if (FlEnd&&!LastSet) break;
             if (LastSet){
                FirstBuf=LastBuf; FirstLine=LastLine+1; FirstSet=1;
                ViewFilePage();
             }
             else if (FirstSet){
                pStart=BufPos[BufNo][BufLines[BufNo]];
                if (!Rest) Rest=(FlBuff[BufNo]+FlBuffLen)-pStart;
                if (FirstBuf==BufNo) LineSeq=BufLines[BufNo]-FirstLine+1;
                else LineSeq=BufLines[FirstBuf]-FirstLine+BufLines[BufNo]+1;
                ViewFileNew(); goto KEY;
             }
             break;
          case HOME:
             BufNo=0; BufLines[0]=BufLines[1]=0; FlPos[0]=FlPos[1]=0;
             rc=fseek(Fl,0,SEEK_SET);
             Rest=fread(FlBuff[0],1,FlBuffLen,Fl);if (Rest<FlBuffLen) FlEnd=1; else FlEnd=0;
             pStart=FlBuff[BufNo];
             LineEnd=0; LineSeq=1; FirstBuf=FirstLine=FirstSet=LastBuf=LastLine=LastSet=0;
             ViewFileNew();
             break;
          case END:
             BufNo=0; BufLines[0]=BufLines[1]=0; FlPos[0]=FlSize;
             LineSeq=RowMax-1; ViewFileRewind();
             FirstBuf=BufNo?0:1; FirstLine=ix; FirstSet=1; 
             ViewFilePage();
             break;
          default:;
       }
    } while(KeyInfo.chChar!=ESC&&KeyInfo.chChar!=ENTER);
    fclose(Fl);
    RedrawScreen();
 }

/**** ViewFileLine ***********************************************/
 void ViewFileLine(void)
 {
    for (i=FndCRLF=0;i<ColMax;++i)
       if (!memcmp(pStart+i,CRLF,2)) {FndCRLF=1;break;}
    memset(WkBuff,0,sizeof(WkBuff)); memcpy(WkBuff,pStart,i);
    VioWrtCharStrAtt(WkBuff,ColMax,LineSeq,0,AtrViewFl,hvio);
    pStart+=i; LineEnd=i%ColMax;
    if (FndCRLF){
       VioWrtCharStrAtt(CRLFDISP,1,LineSeq,LineEnd,AtrCRLFDISP,hvio);
       pStart+=2; LineEnd=0;
    }
 }

/**** ViewFileNew ************************************************/
 void ViewFileNew(void)
 {
    if (!FlEnd&&!Rest) {rc=fseek(Fl,FlPos[BufNo]+(pStart-BufPos[BufNo][0]),SEEK_SET);ViewFileRead();}
    while (LineSeq<RowMax&&Rest){
       /*1行表示*/
       ++BufLines[BufNo]; BufPos[BufNo][BufLines[BufNo]-1]=pStart;
       if (LineSeq==1) {FirstBuf=BufNo;FirstLine=BufLines[BufNo]-1;FirstSet=1;}
       else if (LineSeq==RowMax-1) {LastBuf=BufNo;LastLine=BufLines[BufNo]-1;LastSet=1;}
       for (i=FndCRLF=0;i<Rest-1&&i<ColMax;++i) if (!memcmp(pStart+i,CRLF,2)) {FndCRLF=1;break;}
       memset(WkBuff,0,sizeof(WkBuff)); memcpy(WkBuff,pStart,i);
       VioWrtCharStrAtt(WkBuff,ColMax,LineSeq,0,AtrViewFl,hvio);
       pStart+=i; Rest-=i; LineEnd=i%ColMax;
       if (FndCRLF){
          VioWrtCharStrAtt(CRLFDISP,1,LineSeq,LineEnd,AtrCRLFDISP,hvio);
          pStart+=2; Rest-=2; LineEnd=0;
       }
       /*ﾊﾞｯﾌｧの最後かつﾌｧｲﾙの最後の残り1ﾊﾞｲﾄ出力*/
       if (!i&&Rest==1&&FlEnd){
          VioWrtCharStrAtt(pStart,Rest,LineSeq,LineEnd,AtrViewFl,hvio); Rest=0; break; pStart-=Rest;
       }
       if (LineEnd&&Rest&&FlEnd){
          VioWrtCharStrAtt(pStart,Rest,LineSeq,LineEnd,AtrViewFl,hvio); Rest=0; break; pStart-=Rest;
       }
       if (!LineEnd) {++LineSeq;BufPos[BufNo][BufLines[BufNo]]=pStart;}

       /*ﾊﾞｯﾌｧの最後で次のﾊﾞｯﾌｧ使用*/
       if (LineEnd||Rest<2){
          if (LineEnd) {pStart-=LineEnd;--BufLines[BufNo];}
          rc=fseek(Fl,FlPos[BufNo]+(pStart-BufPos[BufNo][0]),SEEK_SET);
          ViewFileRead();
       }
    }
 }

/**** ViewFilePage ***********************************************/
 void ViewFilePage(void)
 {
    /*FirstBufの残り出力*/
    for(LineSeq=1,ix=FirstLine,LastSet=0;ix<BufLines[FirstBuf]&&LineSeq<RowMax;++ix,++LineSeq){
       if (LineSeq==RowMax-1) {LastBuf=FirstBuf;LastLine=ix;LastSet=1;}
       pStart=BufPos[FirstBuf][ix]; ViewFileLine();
    }
    /*FirstBufでない方が最新なら出力*/
    if (FirstBuf!=BufNo&&BufLines[BufNo])
       for(ix=0;ix<BufLines[BufNo]&&LineSeq<RowMax;++ix,++LineSeq){
          if (LineSeq==1) {FirstBuf=BufNo;FirstLine=ix;FirstSet=1;}
          if (LineSeq==RowMax-1) {LastBuf=BufNo;LastLine=ix;LastSet=1;}
          pStart=BufPos[BufNo][ix]; ViewFileLine();
       }
    /*ﾌｧｲﾙに残りあれば出力*/
    if (LineSeq<RowMax-1&&(!FlEnd||Rest)) {pStart=BufPos[BufNo][BufLines[BufNo]]; ViewFileNew();}
    if (LineSeq<RowMax-1) VioWrtNChar(" ",ColMax*(RowMax-LineSeq+1),LineSeq,LineEnd,hvio);
 }

/**** ViewFileRead ***********************************************/
 void ViewFileRead(void)
 {
    BufNo=BufNo?0:1; BufLines[BufNo]=0; if (BufNo==FirstBuf) FirstSet=0;
    FlPos[BufNo]=ftell(Fl); memset(FlBuff[BufNo],0,sizeof(FlBuff[0]));
    Rest=fread(FlBuff[BufNo],1,FlBuffLen,Fl); if (Rest<FlBuffLen) FlEnd=1; else FlEnd=0;
    pStart=BufPos[BufNo][0]=FlBuff[BufNo];
 }

/**** ViewFileRewind *********************************************/
 void ViewFileRewind(void)
 {
    USHORT rRest,rBufNo,rLine=0; Rest=FlEnd=0;
    do {
       /*BufNoでないﾊﾞｯﾌｧへRewind*/
       if (FlPos[BufNo]>FlBuffLen) rc=fseek(Fl,FlPos[BufNo]-FlBuffLen,SEEK_SET);
       else rc=fseek(Fl,0,SEEK_SET);
       FlPos[rBufNo=BufNo?0:1]=ftell(Fl);
       rRest=fread(pStart=FlBuff[rBufNo],1,FlBuffLen,Fl);
       if (rBufNo==LastBuf) LastSet=0;
       if (FlPos[rBufNo]){
          for (i=0;i<FlBuffLen-1;++i) if (!memcmp(pStart+i,CRLF,2)) break;
          /*最後の2ﾊﾞｲﾄがCRLFの場合も調整なし*/
          if (i<FlBuffLen-2) {pStart+=i+2; rRest-=i+2; FlPos[rBufNo]+=i+2;}
       }
       else rRest=FlPos[BufNo];
       
       /*rBufNoﾊﾞｯﾌｧ内のLineをｶｳﾝﾄ*/
       BufLines[rBufNo]=0; BufPos[rBufNo][0]=pStart;
       while (rRest>1){
          ++BufLines[rBufNo]; BufPos[rBufNo][BufLines[rBufNo]-1]=pStart;
          for (i=FndCRLF=0;i<rRest-1&&i<ColMax;++i) if (!memcmp(pStart+i,CRLF,2)) {FndCRLF=1;break;}
          pStart+=i; rRest-=i; LineEnd=i%ColMax;
          if (FndCRLF) {pStart+=2; rRest-=2; LineEnd=0;}
          if (!LineEnd) BufPos[rBufNo][BufLines[rBufNo]]=pStart;
          else --BufLines[rBufNo];
       }
       rLine=BufLines[rBufNo];
       if (rLine<LineSeq) {BufNo=rBufNo; LineSeq-=rLine; rLine=0;}
       else {ix=rLine-LineSeq; LineSeq=0;}
    } while(rLine<LineSeq&&FlPos[rBufNo]);
 }

/**** ViewInfFile ************************************************/
 void ViewInfFile(void)
 {
    BoxLineAttr=GrayBBlue;
    memcpy(MsgTxt[0],"ＩＮＦファイルを　示します　　",30);
    memcpy(MsgTxt[0]+16,Hyou,2);
    memset(MsgTxt[1],0,30);
    memcpy(MsgTxt[2],"   INF:                       ",30);
    memset(MsgTxt[3],0,30);
    memcpy(MsgTxt[4],"   Enter:実行  Esc:取消",23);
    memcpy(MsgTxt[2]+8,FlDis[SelFl].Nm+29,14);
    MsgTxtLen[0]=30; MsgTxtLen[1]=1; MsgTxtLen[2]=30; MsgTxtLen[3]=1;
    MsgTxtLen[4]=23; MsgTxtLen[5]=0;
    MSGBOXKBDINWHILECR
    {
       memset(FulFlNm,'\0',sizeof(FulFlNm));
       memcpy(FulFlNm,"VIEW.EXE",8);
       StartData.PgmTitle   = FlDis[SelFl].Nm+29;
       StartData.PgmName    = FulFlNm;
       StartData.PgmInputs  = FlDis[SelFl].Nm+29;
       StartData.PgmControl = SSF_CONTROL_VISIBLE;
       memset(StartData.ObjectBuffer,0,sizeof(StartData.ObjectBuffer));
       rc = DosStartSession(&StartData, &SessID, &ProcID); MSGBOXCLEAR
    }
 }

