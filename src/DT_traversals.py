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

def depth_first_search_iterative(root_node: BinaryTreeNode) -> List[BinaryTreeNode]:
    results: List[BinaryTreeNode] = []
    if not results: results

    stack: List[BinaryTreeNode] = []
    stack.append(root_node)
    while stack.__len__() > 0:
        cur_node = stack.pop()
        results.append(cur_node)
        if(cur_node.right_node): stack.append(cur_node.right_node)
        if(cur_node.left_node): stack.append(cur_node.left_node)

    return results

def depth_first_search_recursive(root_node: BinaryTreeNode) -> List[BinaryTreeNode]:
    if not root_node:
        return []

    left_values = depth_first_search_recursive(root_node.left_node)
    right_values = depth_first_search_recursive(root_node.right_node)
    all = []
    all.append(root_node)
    all.extend(left_values)
    all.extend(right_values)
    return all


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

# Time Complexity: O(N)
# Space Complexity: O(N)
def tree_includes(root_node: BinaryTreeNode, target: Any) -> Union[List[BinaryTreeNode], bool]:
    if not root_node: return False
    queue: List[BinaryTreeNode] = [root_node]
    while(queue.__len__() > 0):
        cur_node = queue[0]
        if(cur_node.data == target): return True
        queue = remove_first(queue)
        if(cur_node.left_node): queue.append(cur_node.left_node)
        if(cur_node.right_node): queue.append(cur_node.right_node)

    return False

# Time Complexity: O(N)
# Space Complexity: O(N)
def tree_includes_recursively(root_node: BinaryTreeNode, target: Any) -> Union[List[BinaryTreeNode], bool]:
    if not root_node: return False
    if(root_node.data == target): return True

    return tree_includes_recursively(root_node.left_node, target) or \
    tree_includes_recursively(root_node.right_node, target)

d_node = BinaryTreeNode("D Node")
e_node = BinaryTreeNode("E Node")
b_node = BinaryTreeNode("B Node", d_node, e_node)
f_node = BinaryTreeNode("F Node")
c_node = BinaryTreeNode("C Node", f_node)
root_node = BinaryTreeNode("A Node", b_node, c_node) 
r_BFS = breadth_first_search(root_node)
r_DFS = depth_first_search_iterative(root_node)
r_DFS_recursive = depth_first_search_recursive(root_node)
includes = tree_includes(root_node, "| Node")
includes_recursion = tree_includes_recursively(root_node, "A Node")

for i in r_BFS:
    print(i.data)
print("------------")
for i in r_DFS:
    print(i.data)
print("------------")
for i in r_DFS_recursive:
    print(i.data)
print("------------")
print(includes)
print(includes_recursion)





print("------ Tree Sum ------")
d_node = BinaryTreeNode(4)
e_node = BinaryTreeNode(2)
b_node = BinaryTreeNode(11, d_node, e_node)
f_node = BinaryTreeNode(1)
c_node = BinaryTreeNode(4, f_node)
root_node = BinaryTreeNode(3, b_node, c_node) 
print(breadth_first_search(root_node))