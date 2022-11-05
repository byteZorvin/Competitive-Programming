class TrieNode: 
    def __init__(self):
        self.word = False
        self.children = defaultdict(TrieNode)

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for i in word: 
            node = node.children[i]
        node.word = True

    def search(self, word: str) -> bool:
        node = self.root
        for i in word: 
            if i not in node.children:
                return False
            node = node.children[i]
        return node.word

    def startsWith(self, word: str) -> bool:
        node = self.root
        for i in word: 
            if i not in node.children:
                return False
            node = node.children[i]
        return True