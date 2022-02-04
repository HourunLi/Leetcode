class Trie(object):

    def __init__(self):
        self.children = [None] * 26
        self.isWord = False

    def serchPrefix(self, prefix):
        node = self
        for ch in prefix:
            num = ord(ch) - ord('a')
            if not node.children[num]:
                return None
            node = node.children[num]
        return node

    def insert(self, word):
        node = self
        for ch in word:
            num = ord(ch) - ord('a')
            if not node.children[num]:
                node.children[num] = Trie()
            node = node.children[num]
        node.isWord = True
        return

    def search(self, word):
        node = self.serchPrefix(word)
        return node is not None and node.isWord

    def startsWith(self, prefix):
        return self.serchPrefix(prefix) is not None


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
