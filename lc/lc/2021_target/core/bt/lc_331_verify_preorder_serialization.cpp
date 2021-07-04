class Solution {
public:
    bool isValidSerialization(string preorder) {

        istringstream iss(preorder);
        int nullcnt = 0, nodecnt = 0;

        string tmp;
        vector<string> vec;

        while(getline(iss, tmp, ',')) vec.push_back(tmp);

        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] != "#")
                nodecnt++;
            else
                nullcnt++;

            if (nullcnt >= nodecnt + 1 && i != vec.size() - 1) return false;
        }

        return nullcnt == nodecnt + 1;

    }
};


bool isValidSerialization(string preorder) {
	int degree = 1;
	string temp;
	stringstream ss;
	ss << preorder;
	while (getline(ss, temp, ',')) {
		degree--;
		if (degree < 0)
			return false;
		if (temp[0] != '#')
			degree += 2;
	}
	return degree == 0;
}
