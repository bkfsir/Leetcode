class Solution {
public:
    //递归中出现了好多重复的计算
    //考虑使用动态规划

    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        length = s1.length();
        if (length != s2.length())
            return false;
        if (0 == length)
            return true;

        //构造数组，用于存储每次递归的结果
        //从而避免下次做重复的工作，提高速度
        //在逻辑上构建三维数组
        int arraySize = length*length*length;
        info = new int[arraySize];
        memset(info, -1, arraySize*sizeof(int));
        bool ret = isScarm(s1, s2, length, 0, 0);
        delete[] info;
        return ret;
    }

private:
    bool isScarm(const string& s1, const string& s2, int subLen, int indexIn_s1, int indexIn_s2)
    {     
        int targetIndex = indexIn_s1*length*length + indexIn_s2 * length + subLen - 1;
        if (-1 != info[targetIndex])
            return (info[targetIndex] == 1) ? true : false;
        string tempS1 = s1.substr(indexIn_s1, subLen);
        string tempS2 = s2.substr(indexIn_s2, subLen);

        if (tempS1 == tempS2)
        {
            info[targetIndex] = 1;
            return true;
        }
        else if (1 == subLen)
        {
            info[targetIndex] = 0;
            return false;
        }
            
        
        std::sort(tempS1.begin(), tempS1.end());
        std::sort(tempS2.begin(), tempS2.end());
        if (tempS1 != tempS2)
        {
            info[targetIndex] = 0;
            return false;
        }

        for (int i = 1; i < subLen; i++)
        {
            if (isScarm(s1, s2, i, indexIn_s1, indexIn_s2) && isScarm(s1, s2, subLen - i, indexIn_s1 + i, indexIn_s2 + i))
            {
                info[targetIndex] = 1;
                return true;
            }

            if (isScarm(s1, s2, i, indexIn_s1, indexIn_s2 + subLen - i) && isScarm(s1, s2, subLen - i, indexIn_s1 + i, indexIn_s2))
            {
                info[targetIndex] = 1;
                return true;
            }
        }
        info[targetIndex] = 0;
        return false;
    }

    int length;
    int *info;
};