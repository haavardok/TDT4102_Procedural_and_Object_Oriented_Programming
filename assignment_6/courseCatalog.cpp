#include "courseCatalog.hpp"

// Problem 3b
/**
 * @brief Member function of CourseCatalog that writes a new course into course map
 * 
 * @param const std::string& courseCode
 * @param const std::string& courseName
 */
void CourseCatalog::addCourse(const std::string& courseCode, const std::string& courseName)
{
    courses.insert({courseCode, courseName});
}

/**
 * @brief Member function of CourseCatalog that removes a course from course map by it's course code
 * 
 * @param const std::string& courseCode 
 */
void CourseCatalog::removeCourse(const std::string& courseCode)
{
    courses.erase(courseCode);
}

/**
 * @brief Member function of CourseCatalog that returns course name corresponding to it's course code
 * 
 * @param const std::string& courseCode 
 * @return std::string 
 */
std::string CourseCatalog::getCourse(const std::string& courseCode)
{
    return courses.at(courseCode);
}

/**
 * @brief Operator overloading for writing courses of CourseCatalog to terminal 
 */
std::ostream& operator<<(std::ostream& os, const CourseCatalog& c)
{
    for (const auto& course : c.courses) {
        os << course.first << " " + course.second << std::endl;
    }
    
    return os;
}

// Problem 3e
/**
 * @brief Member function of CourseCatalog that loads courses from a file
 * 
 * @param const std::string& fileName 
 */
void CourseCatalog::loadCoursesFromFile(const std::string& fileName)
{
    std::string line{""};

    std::ifstream inputStream{fileName};
    if (!inputStream) {
        error("Can't open input file ", fileName);
    }

    courses.clear();

    while (std::getline(inputStream, line)) {
        std::stringstream ss{line};
        std::string code{""};
        std::string name{""};

        std::getline(ss, code, ';');
        std::getline(ss, name, ';');
        courses.insert({code, name});
    }
}

/**
 * @brief Member function of CourseCatalog that saves courses to a file
 * 
 * @param const std::string& fileName 
 */
void CourseCatalog::saveCoursesToFile(const std::string& nameOfSavedFile)
{
    std::filesystem::path fileName{nameOfSavedFile};

    std::ofstream outputStream{fileName};
    if (!outputStream) {
        error("Can't open output file ", nameOfSavedFile);
    }

    for (const auto& course : courses) {
        outputStream << course.first << ";" << course.second << std::endl;
    }
}