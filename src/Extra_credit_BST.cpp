#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Student
{
private:
    float exam_scores[3];
    float quiz_scores[3];
    float homework_scores[5];
    float exam_weights[3] = { 15, 15, 25 };
    float quiz_weights[3] = { 5, 5, 5 };
    float homework_weights[5] = { 5, 5, 5, 5, 5 };
    float weight_exam;
    float weight_quiz;
    float weight_homework;
    float total_score;
    string first_name;
    string last_name;
    char grade;
    char calculate_grade()
    {
        char letter_grade;
        total_score = weight_exam + weight_homework + weight_quiz;
        if (total_score > 90)
        {
            letter_grade = 'A';
        }
        else if (total_score > 80 && total_score <= 90)
        {
            letter_grade = 'B';
        }
        else if (total_score > 70 && total_score <= 80)
        {
            letter_grade = 'C';
        }
        else if (total_score > 60 && total_score <= 80)
        {
            letter_grade = 'D';
        }
        else
        {
            letter_grade = 'F';
        }
        grade = letter_grade;
        return letter_grade;
    }
public:
    Student() = default;
    Student(string f_name, string l_name) : first_name(f_name), last_name(l_name) {}
    ~Student() = default;
    void set_exam_scores(float scores[], float weights[])
    {
        for (int i = 0; i < 3; ++i)
        {
            exam_scores[i] = scores[i];
            exam_weights[i] = weights[i];
        }
    }
    void set_quiz_scores(float scores[], float weights[])
    {
        for (int i = 0; i < 3; ++i)
        {
            quiz_scores[i] = scores[i];
            quiz_weights[i] = weights[i];
        }
    }
    void set_hw_scores(float scores[], float weights[])
    {
        for (int i = 0; i < 3; ++i)
        {
            homework_scores[i] = scores[i];
            homework_weights[i] = weights[i];
        }
    }
    void set_exam_scores(float scores[], initializer_list<float> l)
    {
        for (int i = 0; i < 3; ++i)
        {
            exam_scores[i] = scores[i];
            if (l.size())
                exam_weights[i] = *(l.begin() + i);
        }
    }
    void set_quiz_scores(float scores[], initializer_list<float> l)
    {
        for (int i = 0; i < 3; ++i)
        {
            quiz_scores[i] = scores[i];
            if (l.size())
                quiz_weights[i] = *(l.begin() + i);
        }
    }
    void set_hw_scores(float scores[], initializer_list<float> l)
    {
        for (int i = 0; i < 5; ++i)
        {
            homework_scores[i] = scores[i];
            if (l.size())
                homework_weights[i] = *(l.begin() + i);
        }
    }
    void set_letter_grade(char grad) { grade = grad; }
    void set_first_name(const string& f_name) { first_name = f_name; }
    void set_last_name(const string& l_name) { last_name = l_name; }
    float get_exam_weight() const { return weight_exam; }
    float get_hw_weight() const { return weight_homework; }
    float get_quiz_weight() const { return weight_quiz; }
    char get_letter_grade() const { return grade; }
    const string& get_first_name() const { return first_name; }
    const string& get_last_name() const { return last_name; }
    float get_total_score() const { return total_score; }
    char letter_grade()
    {
        float weight_exam = 0, weight_quiz = 0, weight_hw = 0;
        int ctr = 0;
        for (auto& score : exam_scores)
        {
            weight_exam += score * exam_weights[ctr] / 100;
            ++ctr;
        }
        ctr = 0;
        for (auto& score : quiz_scores)
        {
            weight_quiz += score * quiz_weights[ctr] / 100;
            ++ctr;
        }
        ctr = 0;
        for (auto& score : homework_scores)
        {
            weight_hw += score * homework_weights[ctr] / 100;
            ++ctr;
        }
        char letter_grade;
        total_score = weight_exam + weight_hw + weight_quiz;
        if (total_score > 90)
        {
            letter_grade = 'A';
        }
        else if (total_score > 80 && total_score <= 90)
        {
            letter_grade = 'B';
        }
        else if (total_score > 70 && total_score <= 80)
        {
            letter_grade = 'C';
        }
        else if (total_score > 60 && total_score <= 80)
        {
            letter_grade = 'D';
        }
        else
        {
            letter_grade = 'F';
        }
        this->grade = letter_grade;
        this->weight_exam = weight_exam;
        this->weight_quiz = weight_quiz;
        this->weight_homework = weight_hw;
        return letter_grade;
    }
    char letter_grade(float scores[], float weights[])
    {
        int ctr = 0;
        for (int i = 0; i < 3; i++)
        {
            float weight_exam = 0;
            weight_exam += scores[ctr] * weights[ctr] / 100;
            this->weight_exam = weight_exam;
            exam_scores[i] = scores[ctr];
            exam_weights[i] = weights[ctr];
            ++ctr;
        }
        for (int i = 0; i < 3; ++i)
        {
            float weight_quiz = 0;
            weight_quiz += scores[ctr] * weights[ctr] / 100;
            this->weight_quiz = weight_quiz;
            quiz_scores[i] = scores[ctr];
            quiz_weights[i] = weights[ctr];
            ++ctr;
        }
        for (int i = 0; i < 5; ++i)
        {
            float weight_hw = 0;
            weight_hw += scores[ctr] * weights[ctr] / 100;
            this->weight_homework = weight_hw;
            homework_scores[i] = scores[ctr];
            homework_weights[i] = weights[ctr];
            ++ctr;
        }
        return calculate_grade();
    }
    char letter_grade(float scores[], initializer_list<float> l)
    {
        int ctr = 0;
        for (int i = 0; i < 3; i++)
        {
            float weight_exam = 0;
            weight_exam += scores[ctr] * (*(l.begin() + ctr)) / 100;
            this->weight_exam = weight_exam;
            exam_scores[i] = scores[ctr];
            exam_weights[i] = *(l.begin() + ctr);
            ++ctr;
        }
        for (int i = 0; i < 3; ++i)
        {
            float weight_quiz = 0;
            weight_quiz += scores[ctr] * (*(l.begin() + ctr)) / 100;
            this->weight_quiz = weight_quiz;
            quiz_scores[i] = scores[ctr];
            quiz_weights[i] = *(l.begin() + ctr);
            ++ctr;
        }
        for (int i = 0; i < 5; ++i)
        {
            float weight = 0;
            weight += scores[ctr] * (*(l.begin() + ctr)) / 100;
            this->weight_homework = weight;
            homework_scores[i] = scores[ctr];
            homework_weights[i] = *(l.begin() + ctr);
            ++ctr;
        }
        return calculate_grade();
    }
};
void processInputFile(std::string file_name, vector<Student>& stud_list)
{
    std::fstream input_file(file_name, ios::in);
    std::string line;
    while (getline(input_file, line))
    {
        Student s;
        stringstream ss(line);
        string f_name, l_name;
        float score_arr[3];
        float score_arr2[5];
        ss >> f_name;
        ss >> l_name;
        s.set_first_name(f_name);
        s.set_last_name(l_name);
        for (int i = 0; i < 3; ++i)
        {
            float val;
            ss >> val;
            score_arr[i] = val;
        }
        s.set_exam_scores(score_arr, {});
        for (int i = 0; i < 3; ++i)
        {
            float val;
            ss >> val;
            score_arr[i] = val;
        }
        s.set_quiz_scores(score_arr, {});
        for (int i = 0; i < 5; ++i)
        {
            float val;
            ss >> val;
            score_arr2[i] = val;
        }
        s.set_hw_scores(score_arr2, {});
        stud_list.push_back(s);
    }
}
void writeOutputFile(string file_name, const vector<Student>& stud_list)
{
    fstream out_file(file_name, ios::out);
    stringstream ss;
    ss << "Name" << '\t' << "Last" << '\t\t\t\t\t\t\t' << "WE" << '\t' << "WQ" << '\t' << "WA" << '\t'
        << "Sum" << '\t' << "Letter Grade" << '\n';
    for (auto& s : stud_list)
    {
        ss <<setprecision(4) << s.get_first_name() << '\t' << s.get_last_name() << '\t' << s.get_exam_weight() << '\t' << s.get_quiz_weight()
            << '\t' << s.get_hw_weight() << '\t' << s.get_total_score() << '\t' << s.get_letter_grade() << '\n';
    }
    out_file << ss.str();
}
int main(int argc, char* argv[])
{
    string infile_name = "grade.txt";
    string outfile_name = "gradeoutput.txt";
    if (argc >= 2)
    {
        infile_name = argv[1];
    }
    if (argc == 3)
    {
        outfile_name = argv[2];
    }
    else
    {
    }
    vector<Student> students;
    processInputFile(infile_name, students);
    for (auto& student : students)
    {
        student.letter_grade();
    }
    writeOutputFile(outfile_name, students);
}
