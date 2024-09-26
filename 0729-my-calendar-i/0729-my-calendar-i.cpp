struct _pair{
    int start;
    int end;
};
class MyCalendar {
public:
    vector<_pair> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(_pair p : v){
            if (end <= p.start || p.end <= start){
                continue;
            }
            return false;
        }
        v.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */