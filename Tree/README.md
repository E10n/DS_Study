# 트리

https://www.youtube.com/watch?v=LnxEBW29DOw
https://www.youtube.com/watch?v=TdakkF5Xh6o
트리는 계층이고 구조이며 그룹이다.
부모-자식 의 구조를 지니며 더이상 자식이 없는 노드를 leaf(잎) 이라고 부른다.

트리 : 노드가 하나 이상의 자식을 가지는 것
이진트리 : 트리주에 자식을 2개만 가질 수 있는 것
node = [ left | data | P | right ]    =>P는 부모 노드를 가르킨다.
Root node 의 주소는 따로 보관한다. 

순회:이진 트리의 모든 노드를 방문하는 일
1.중순위(inorder) 순회
2.선순위(preorder) 순회
3.후순위(postorder) 순회
4.레벨오더(level-order) 순회 - 큐를 이용하여 구현

이진검색트리 : 부모의 왼쪽자식노드는 부모보다 작은값 오른쪽은 큰값이 있는 이진트리 구조


이진트리 응용 예: Expression Tree, Huffman Code


balanced : 균형이 잡힌 트리(ex red-black tree, AVL tree)
unbalanced

complete binary tree(완전 이진 트리)
 :leaf노드들이 좌 우 좌 우.. 형태를 이루어야됨. 만야 좌 우 우 의경우 완전 이진트리가 아님

 full binary tree
  : 자식노드를 가질거면 2개를 가지고 안가질거면 아예 안가져야함

 perfect binary tree
  : 양쪽으로 빈 공간 없이 가득 찬 트리, 모든노드가 전부 자식노드 2개를 가지고 있음


  트리 예제 1. 전화번호부
