#include <cstdio>
#include <heap>

File mergeN(const std::vector<File>& files)
{
    File output;
    std::vector<Input> inputs;
    for (size_t i = 0; i < files.size(); ++i) {
        //将所有文件类放入数组
        Input input(&files[i]);
        if (input.next()) {
            inputs.push_back(input);
        }
    }
    //make heap with first input of each file
    std::make_heap(inputs.begin(), inputs.end());
    while (!inputs.empty()) { // 还有文件未读完
        std::pop_heap(inputs.begin(), inputs.end());
        output.push_back(inputs.back().value);  //输出堆顶元素的值
        if (inputs.back().next()) { //下次读会继续此文件
            std::push_heap(inputs.begin(), inputs.end());
        } else {
            inputs.pop_back();  //此文件已读完，不参与堆了
        } }
        return output;
}

struct Input
{
    Record value;
    const File* file;
    explicit Input(const File* f);
    bool next();
    bool operator<(const Input& rhs) const
    {
        // make_heap to build min-heap, for merging
        return value > rhs.value;
    }
};
