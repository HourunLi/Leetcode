class Trie:
    def __init__(self):
        self.children = {}
        self.word = ""

    def insert(self, word):
        ptr = self
        for ch in word:
            if ch not in ptr.children:
                ptr.children[ch] = Trie()
            ptr = ptr.children[ch]
        ptr.word = word


class Solution(object):
    def findWords(self, board, words):
        dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]
        n, m = len(board), len(board[0])
        trie = Trie()
        ans = []
        for word in words:
            trie.insert(word)

        def dfs(x, y, trieNode):
            # child func can use var from parent
            ch = board[x][y]
            if ch not in trieNode.children:
                return

            next = trieNode.children[ch]
            if next.word != "":
                ans.append(next.word)
                next.word = ""

            board[x][y] = '#'
            for i in range(4):
                nx, ny = x+dx[i], y+dy[i]
                if nx < 0 or ny < 0 or nx >= n or ny >= m or board[nx][ny] == '#':
                    continue
                dfs(nx, ny, next)
            board[x][y] = ch
            if not next.children:
                trieNode.children.pop(ch)

        for i in range(n):
            for j in range(m):
                dfs(i, j, trie)

        return ans
