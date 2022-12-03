template <typename T>
class kupac {
private:
    vector<T> a;

    void kupacol(int x) {
        if (2 * x + 1 >= size()) return;
        int c1 = 2 * x + 1, c2 = 2 * x + 2;
        if (c2 < size() && a[c1] < a[c2]) swap(c1, c2);
        if (a[x] < a[c1]) {
            swap(a[x], a[c1]);
            kupacol(c1);
        }
    }

    void felszivarog(int x) {
        if (x == 0) return;
        int p = (x - 1) / 2;
        if (a[x] > a[p]) {
            swap(a[x], a[p]);
            felszivarog(p);
        }
    }

public:
    void pop() {
        if (a.size() == 0) return;
        swap(a[0], a.back());
        a.pop_back();
        kupacol(0);
    }

    void push(T v) {
        a.push_back(v);
        felszivarog(a.size() - 1);
    }

    int size() const {
        return a.size();
    }
    T top() const {
        return a.front();
    }
    bool empty() const {
        return a.size() == 0;
    }
};
