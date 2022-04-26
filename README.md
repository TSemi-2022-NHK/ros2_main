# ros2_main R1,R2共通のros用ws
### 工事中
# usage 
環境変数にR1なら
ROBOT R1
R2なら
ROBOT R2
を追加後　main_executor内のmain_execを実行
ros styleなら
ros2 run main_executor main_exec
classical styleなら
./build/main_executor/main_exec
# 注意点
すべてのコードはsrc直下に置くこと
外部リポジトリを利用する場合は必ずgit submoduleを利用すること
自分の名前から始まるブランチ(ex 高橋なら ryuzou ブランチ)を作成し、基本的に各々の細かいコミットはそちら、あるいはそこから派生した機能別のブランチ(ex ryuzou-bno055ブランチなど)で行い、masterブランチには基本的に完成版が置かれているようにすること
