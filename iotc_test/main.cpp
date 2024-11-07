//! [Request definition]
#include <fastcgi++/request.hpp>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>
#include <unistd.h>

class HelloWorld: public Fastcgipp::Request<wchar_t>
{
public:
    // 在构造函数中调用基类构造函数并指定 maxPostSize 的大小
    HelloWorld(size_t maxPostSize = 1024 * 1024)  // 默认设置为1MB，可根据需要调整
        : Fastcgipp::Request<wchar_t>(maxPostSize)
    {
        // 可以在此继续进行其他初始化
        std::cout << "HelloWorld constructor, this address: " << this << std::endl;
    }
    std::string formatAddress(const Fastcgipp::Http::Address& addr) {
    std::ostringstream addressStream;

    // 检查是否为 IPv4 映射地址
    if (std::all_of(addr.m_data.begin(), addr.m_data.begin() + 10, [](unsigned char c) { return c == 0; }) &&
        addr.m_data[10] == 0xff && addr.m_data[11] == 0xff) {
        // 提取 IPv4 映射地址的后四个字节
        addressStream << static_cast<int>(addr.m_data[12]) << "."
                      << static_cast<int>(addr.m_data[13]) << "."
                      << static_cast<int>(addr.m_data[14]) << "."
                      << static_cast<int>(addr.m_data[15]);
    } else {
        // 否则按IPv6格式输出
        addressStream << std::hex;
        for (size_t i = 0; i < Fastcgipp::Http::Address::size; i += 2) {
            addressStream << static_cast<int>((addr.m_data[i] << 8) | addr.m_data[i + 1]);
            if (i < Fastcgipp::Http::Address::size - 2)
                addressStream << ":";
        }
    }

    return addressStream.str();
}

~HelloWorld()
{
    std::cout << "HelloWorld destructor, this address: " << this << std::endl;
}
    std::wstring stringToWString(const std::string& str) {
        // 使用 std::wstring_convert 进行 UTF-8 到宽字符串的转换
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        return converter.from_bytes(str);
    }
//     void render(std::ostream &stream) { 
//         stream << "<p>{ <p>test111111</p><p>system<br />&nbsp;&nbsp;&nbsp;&nbsp;login<br /></p>\
// <p>Remote contentType: application/json</p>\
// <p>Remote authorization: </p>\
// <p>Remote scriptName: /cgi-bin/test.cgi</p>\
// <p>Remote requestMethod: POST</p>\
// <p>Remote requestUri: /cgi-bin/test.cgi/system/login</p>\
// <p>Remote ifModifiedSince: 0</p>\
// <p>Remote remotePort: 59889</p>\
// <p>Remote Address: ::ffff:192.168.22.133</p>\
// <p>Remote Address: ::ffff:192.168.36.12</p>}</p>";
//     }

    void render(std::wostringstream  &stream) { 
        std::string narrowStr = "<p>{ <p>test111111</p><p>system<br />&nbsp;&nbsp;&nbsp;&nbsp;login<br /></p>\
<p>Remote contentType: application/json</p>\
<p>Remote authorization: </p>\
<p>Remote scriptName: /cgi-bin/test.cgi</p>\
<p>Remote requestMethod: POST</p>\
<p>Remote requestUri: /cgi-bin/test.cgi/system/login</p>\
<p>Remote ifModifiedSince: 0</p>\
<p>Remote remotePort: 59889</p>\
<p>Remote Address: ::ffff:192.168.22.133</p>\
<p>Remote Address: ::ffff:192.168.36.12</p>}</p>";    
        std::wstring wideStr = stringToWString(narrowStr);
        stream << wideStr;
    }
    
    bool response() override {
        std::wcout << L"contentType:" << this->environment().contentType << std::endl;
        std::wcout << L"requestOtherData size:" << this->environment().requestOtherData.size() << std::endl;
        std::cout << "Req.ContentLength szie: " << this->environment().contentLength << std::endl;
        

        std::cout << "Processing request, this address: " << this << std::endl;
        out << "Content-Type: text/html\r\n\r\n";
        out << "<html><head><title>Request Parameters</title></head><body>";
        // 获取当前时间
         auto start = std::chrono::high_resolution_clock::now();
        // std::ostringstream os; // 使用ostringstream
        // render(os); // 写入到ostringstream
        // // 将字符串转换为宽字符串
        // std::string narrowStr = os.str(); // 获取 std::string 类型的内容

        // 将字符串转换为宽字符串
        // std::wstring wideStr = stringToWString(narrowStr);

        // out << wideStr; // 将转换后的宽字符串写入到 out

        std::wostringstream os; // 使用宽字符串流
        render(os); // 写入到宽字符串流
        out << os.str(); // 将宽字符串流中的内容写入到 out
        // 获取结束时间
    auto end = std::chrono::high_resolution_clock::now();

    // 计算持续时间
    std::chrono::duration<double, std::milli> duration = end - start;

    // 输出持续时间
    std::cout << "程序运行时间: " << duration.count() << " 毫秒" << std::endl;
        // std::wcout << L"Content-Type: " << this->environment().contentType << std::endl;

        std::multimap<std::wstring, std::wstring> Entries = this->environment().posts;

        // if(environment().posts.size())
        // {
        //     for(const auto& post: environment().posts)
        //     {
        //         std::wstring  key = post.first;
        //         std::wstring  value = post.second;
                
        //         std::wcout << L"GET parameter: " << key << L" = " << value  << std::endl;
        //     }
        // }
        // std::multimap<std::wstring, Fastcgipp::Http::File<std::wstring>> Files = this->environment().files;
        
        if(environment().files.size())
        {
            for(const auto& file: environment().files)
            {
                std::wstring  key = file.first;
                std::wstring  filename = file.second.filename;
                std::wstring  contenttype = file.second.contentType;
                size_t  szie = file.second.size;
                char*  data = file.second.data.get();
                std::wcout << L"GET parameter: " << key << L" = " << filename << L" contenttype= " << contenttype  << std::endl;
                std::cout << "size:" << szie << std::endl;
            }
        }
      
        // std::multimap<std::wstring, std::wstring> Entries = this->environment().posts;
        // 解析并显示 GET 请求参数
        std::wstring contentType = this->environment().contentType;
        std::wstring authorization = this->environment().authorization;
        std::wstring scriptName = this->environment().scriptName;
        Fastcgipp::Http::RequestMethod requestMethod = this->environment().requestMethod;
        std::wstring requestUri = this->environment().requestUri;
        Fastcgipp::Http::Address remoteAddress = this->environment().remoteAddress;
        Fastcgipp::Http::Address serverAddress = this->environment().serverAddress;
        // for (const auto& [key, value] : this->environment().gets) {
        //     std::wcout << L"GET parameter: " << key << L" = " << value << std::endl;
        // }
        // for (const auto& segment : this->environment().pathInfo) {
        //     std::wcout << L"Path segment: " << segment << std::endl;
        // }

        std::multimap<std::wstring, std::wstring> cookies = this->environment().cookies;
        for (const auto& cookie : cookies) {
            std::wstring cookieName = cookie.first;
            std::wstring cookieValue = cookie.second;
            
            // 将 wchar_t 转换为 std::string 输出
            std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
            std::string cookieNameStr = converter.to_bytes(cookieName);
            std::string cookieValueStr = converter.to_bytes(cookieValue);

            std::cout << "Cookie: " << cookieNameStr << " = " << cookieValueStr << std::endl;
        }

        std::multimap<std::wstring, std::wstring> gets = this->environment().gets;
        for (const auto& get : gets) {
            std::wstring cookieName = get.first;
            std::wstring cookieValue = get.second;
            
            // 将 wchar_t 转换为 std::string 输出
            std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
            std::string cookieNameStr = converter.to_bytes(cookieName);
            std::string cookieValueStr = converter.to_bytes(cookieValue);

            std::cout << "gets: " << cookieNameStr << " = " << cookieValueStr << std::endl;
        }

        std::multimap<std::wstring, std::wstring> posts = this->environment().posts;
        for (const auto& cookie : posts) {
            std::wstring cookieName = cookie.first;
            std::wstring cookieValue = cookie.second;
            
            // 将 wchar_t 转换为 std::string 输出
            std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
            std::string cookieNameStr = converter.to_bytes(cookieName);
            std::string cookieValueStr = converter.to_bytes(cookieValue);

            std::cout << "posts: " << cookieNameStr << " = " << cookieValueStr << std::endl;
        }

       std::cout << "contentLength:"  << this->environment().contentLength <<std::endl;
        //     //! Container with all url-encoded GET data
        //     std::multimap<
        //         std::basic_string<charT>,
        //         std::basic_string<charT>> gets;

        //     //! Container of none-file POST data
        //     std::multimap<
        //         std::basic_string<charT>,
        //         std::basic_string<charT>> posts;

        //     //! Container of file POST data
        //     std::multimap<
        //         std::basic_string<charT>,
        //         File<charT>> files;
        std::string firstPathInfoElement;
        if (!this->environment().pathInfo.empty()) {
            std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
            for(int i  = 0; i < this->environment().pathInfo.size(); i++)
            {
                firstPathInfoElement = converter.to_bytes(this->environment().pathInfo[i]);
                std::cout << "Path segment: " << firstPathInfoElement << std::endl;
            }
            
        }
        


        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        firstPathInfoElement = converter.to_bytes(this->environment().requestJsonData);
        std::cout << "requestJsonData: " << firstPathInfoElement  << "length:" << firstPathInfoElement.length()<< std::endl;


        std::time_t ifModifiedSince = this->environment().ifModifiedSince;
        uint16_t remotePort = this->environment().remotePort;
        if(this->environment().pathInfo.size())
        {
            out <<
        L"<p>";
            std::wstring preTab;
            for(const auto& element: environment().pathInfo)
            {
                out << preTab << element 
                    << L"<br />";
                preTab += L"&nbsp;&nbsp;&nbsp;&nbsp;";
            }
            out <<
        L"</p>";
        }
        else
            out <<
        L"<p>No Path Info</p>";
        // out << "<p>Remote pathInfo: " << this->environment().pathInfo[0].c_str() << "</p>";
        out << "<p>Remote contentType: " << contentType.c_str() << "</p>";
        out << "<p>Remote authorization: " << authorization.c_str() << "</p>";
        out << "<p>Remote scriptName: " << scriptName.c_str() << "</p>";
        out << "<p>Remote requestMethod: " << requestMethod << "</p>";
        out << "<p>Remote requestUri: " << requestUri.c_str() << "</p>";
        out << "<p>Remote ifModifiedSince: " << this->environment().ifModifiedSince << "</p>";
        out << "<p>Remote remotePort: " << this->environment().remotePort << "</p>";
        std::cout << "<p>Remote remotePort: " << remotePort << "</p>" << std::endl;
        
        
        std::string addressStr = formatAddress(remoteAddress);
        std::cout << "<p>Remote Address: " << addressStr << "</p>" << std::endl;
        out << "<p>Remote Address: " << this->environment().remoteAddress << "</p>";
        

        
        std::string saddressStr = formatAddress(serverAddress);
        std::cout << "<p>Remote sAddress: " << saddressStr << "</p>" << std::endl;
        out << "<p>Remote Address: " << this->environment().serverAddress<< "</p>";
        
        // // 获取远程端口
        // int port = remoteAddress.port;
        // out << "<p>Remote Port: " << port << "</p>";


        

        out << "</body></html>";
        return true;
    }
};
//! [Return]

//! [Manager]
#include <fastcgi++/manager.hpp>

int main()
{
    Fastcgipp::Manager<HelloWorld> manager;
    //! [Manager]
    //! [Signals]
    manager.setupSignals();
    //! [Signals]
    //! [Listen]
    int count = 0;
    while(true)
    {
        bool ret = manager.listen("127.0.0.1", "8030");
        if(ret)
        {
            break;
        }else
        {   
            count++;
            sleep(1);
            printf("try count:%d\n", count);
        }
    }
    //! [Listen]
    //! [Start]
    manager.start();
    //! [Start]
    //! [Join]
    manager.join();
    

    return 0;
}
//! [Join]
