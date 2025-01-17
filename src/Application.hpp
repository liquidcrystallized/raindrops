#ifndef RAINDROPS_APPLICATION_HPP
#define RAINDROPS_APPLICATION_HPP


class Application {
public:
    static Application& instance();

    void run();

private:
    static Application m_instance;
};


#endif //RAINDROPS_APPLICATION_HPP
