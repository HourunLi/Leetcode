class MyCalendar:
    def __init__(self):
        from sortedcontainers import SortedList
        self.data = SortedList()

    def book(self, start: int, end: int) -> bool:
        idx = self.data.bisect_right(start)
        if idx == len(self.data) or idx % 2 == 0 and self.data[idx] >= end:
            self.data.add(start)
            self.data.add(end)
            return True
        return False
        # Your MyCalendar object will be instantiated and called as such:
        # obj = MyCalendar()
        # param_1 = obj.book(start,end)
