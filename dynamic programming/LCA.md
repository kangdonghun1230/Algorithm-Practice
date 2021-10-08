## LCA(Lowest Common Ancestor) algorithm
LCA algorithm은 이름 그대로 최소 공통 조상을 찾는 알고리즘입니다.

- 이진 트리(Binary Tree)가 아닌 일반 트리에서도 사용 가능하다.
- dynamic programming의 일종으로 O(lgN)의 time complexity를 갖는다.
- 트리(Tree) 구조 내의 두 노드 사이의 거리를 빠르게 구하기 위해 사용 가능하다.

알고리즘의 진행 순서
0. Tree 구조를 만듭니다.
1. 모든 노드에 대해 DFS(Depth First Search)를 이용하여 depth를 구합니다. (with DFS function)
2. 모든 노드의 2^i th parent node 정보를 구합니다. (with setParent function)
3. 거리를 구하고자 하는 두 노드의 depth를 동일하게 맞춥니다. depth가 작은 쪽으로 값을 통일시킵니다. (with LCA function)
4. 최상단 노드부터 탐색하며(최대 i th parent부터 탐색하며) 가장 멀리있으며 일치하지 않는 같은 depth의 node를 찾습니다. (with LCA function)
5. 4번 과정의 결과로 두 노드는 공통 조상의 바로 아래의 자식이 되고, 두 노드 중 하나의 2^0 th node를 return합니다. (return parent[x][0])

2^i th parent에 대한 정보를 미리 setting한 후 탐색을 통해 공통 조상 노드를 찾는 알고리즘이기 때문에, O(lgN)의 time complexity를 갖는 algorithm입니다.

- Reference
   - https://blog.naver.com/PostView.naver?blogId=ndb796&logNo=221282478466&parentCategoryNo=&categoryNo=128&viewDate=&isShowPopularPosts=false&from=postList
   - https://www.crocus.co.kr/660
