import sys
sys.setrecursionlimit(10000)

class Node:
    def __init__(self, num, left, right):
        self.num = num
        self.left = left
        self.right = right

def make_tree(start, end, nodeinfo): # start <= i < end의 nodeinfo[i]로 tree를 만들어 가장 상위 노드를 반환
    if start >= end:
        return None
    
    idx = nodeinfo.index(max(nodeinfo[start:end], key=lambda n: n[1])) # 상위 노드의 index
    return Node(nodeinfo[idx][2], make_tree(start, idx, nodeinfo), make_tree(idx + 1, end, nodeinfo))

def preorder(node): # 전위 순회
    if node == None:
        return []
    
    return [node.num] + preorder(node.left) + preorder(node.right)

def postorder(node): # 후위 순회
    if node == None:
        return []
    
    return postorder(node.left) + postorder(node.right) + [node.num]

def solution(nodeinfo):
    for i in range(len(nodeinfo)):
        nodeinfo[i].append(i + 1) # 노드의 번호 적기
    
    nodeinfo.sort(key=lambda n: n[0]) # x좌표를 기준으로 오름차순 정렬
    
    root = make_tree(0, len(nodeinfo), nodeinfo)
    
    return [preorder(root), postorder(root)]