struct _pair{
    int start;
    int end;
};
class MyCalendarTwo {
public:
    vector<_pair> bookList;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        vector<_pair> doubleBookList;
        for(_pair book : bookList){
            if(book.start >= end || book.end <= start){
                continue;
            }
            int s = max(book.start, start);
            int e = min(book.end, end);
            for(_pair db: doubleBookList){
                if(db.start >= e || db.end <= s){
                    continue;
                }
                return false;
            }
            doubleBookList.push_back({s, e});
        }
        bookList.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */