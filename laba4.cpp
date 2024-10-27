#include <iostream>
#include <vector>

using namespace std;

float mean(const vector<float> x) {
	float sum = 0;
	for (int i = 0; i < x.size(); i++) {
		sum += x[i];
	}
	return sum / x.size();
}

pair<float, float> minMax(const vector<float> v) {
	float min = v[0];
	float max = v[0];
	for (int i = 0; i < v.size(); i++) {
		if (min > v[i]) {
			min = v[i];
		}
		if (max < v[i]) {
			max = v[i];
		}
	}
	pair<float, float> res = { min, max };
	return res;
}

int argmax(const vector<float> v) {
	float max = v[0];
	if (v.size() == 0) {
		return -1;
	}
	else
	{
		for (int i = 0; i < v.size(); i++) {
			if (max < v[i]) {
				max = v[i];
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (max == v[i]) {
			return i;
		}
	}
}

void sort(vector<float>& v) {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = 0; j < v.size()- 1; j++) {
			if (v[j] < v[j + 1]) {
				float temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

bool remove_first_negative_element(vector<int>& vec, int& removed_element) {
	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i] < 0) {
			removed_element = vec[i];
			vec.erase(vec.begin() + i);
			return true;
		}
	}
	return false;
}

string replace(const std::string& str, const std::string& old, const std::string& new_string) {
	string res = str;
	int temp = 0;
	for (int i = 0; i < str.length(); i++) {
		string check = "";
		if (str[i] == old[0]) {
			for (int j = 0; j < old.length(); j++) {
				if (str[i + j] == old[j]) {
					check.push_back(str[i + j]);
				}
			}
			if (check == old) {
				for (int j = 0; j < old.length(); j++) {
					res[i + j + temp] = new_string[j];
				}
				if (old.length() < new_string.length()) {
					for (int j = old.length(); j < new_string.length(); j++) {
						res.insert(res.begin() + i + j + temp, new_string[j]);
						temp++;
					}
				}

				if (old.length() > new_string.length()) {
					for (int j = i + new_string.length(); j < old.length(); j++) {
						res.erase(res.begin() + j + temp);
						temp--;
					}
				}
			}
		}
		check = "";
	}
	return res;
}

vector<string> split(const std::string& st, char sep) {
	int count_char = 0;
	for (int i = 0; i < st.size(); i++) {
		if (st[i] == sep) {
			count_char++;
		}
	}
	vector<string> v(count_char + 2);
	int word_number = 0;
	for (int i = 0; i < st.size(); i++) {
		if (st[i] != sep) {
			v[word_number].push_back(st[i]);
		}
		else
		{
			word_number++;
		}
	}
	return v;
}

string join(const vector<string>& v, const string& sep) {
	string res = "";
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			res.push_back(v[i][j]);
		}
		for (int j = 0; j < sep.size(); j++) {
			res.push_back(sep[j]);
		}
	}
	res.erase(res.begin() + res.size() - 1);
	return res;
}

int main()
{
	vector<string> arr = { "Can", "you", "can", "a", "can", "as", "a", "canner", "can", "can", "a", "can?" };
	string str = join(arr, "AAAAA");
	cout << str;
}