from typing import Any, Union, List

class BinaryTreeNode:
    def __init__(self, data: Any, left_node: Union[Any, None] = None, right_node: Union[Any, None] = None):
        self.data = data
        self.left_node = left_node
        self.right_node = right_node

def remove_first(arr: List):
    aux = []
    for e in range(1, len(arr)):
        aux.append(arr[e])
    return aux

def breadth_first_search(root_node: BinaryTreeNode) -> List[BinaryTreeNode]:
    results = []
    if not root_node: results

    queue: List[BinaryTreeNode] = [root_node]
    while len(queue) > 0:
        cur_node = queue[0]
        results.append(cur_node)
        queue = remove_first(queue)
        if(cur_node.left_node): queue.append(cur_node.left_node)
        if(cur_node.right_node): queue.append(cur_node.right_node)

    return results


d_node = BinaryTreeNode("D Node")
e_node = BinaryTreeNode("E Node")
b_node = BinaryTreeNode("B Node", d_node, e_node)
f_node = BinaryTreeNode("F Node")
c_node = BinaryTreeNode("C Node", f_node)
root_node = BinaryTreeNode("A Node", b_node, c_node) 
r = breadth_first_search(root_node)

for i in r:
    print(i.data)