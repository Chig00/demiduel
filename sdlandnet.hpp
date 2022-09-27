#pragma once

#include <string>
#include <sstream>
#include <memory>
#include <array>
#include <vector>
#include <exception>
#include <stdexcept>
#include <cmath>
#include <ctime>
#include <chrono>
#include <limits>
#include <random>
#include <SDL.h>
#include <SDL_net.h>

// System, Logging, Timer, and Pseudo-Random Number Generation
//{
/**
 * A namespace for initialisation and shutdown functions.
 */
namespace System {
    // Constants
    //{
    // The current version of the library.
    constexpr int VERSION_LENGTH = 4;
    constexpr int VERSION[VERSION_LENGTH] = {4, 2, 0, 0};
    
    // The number of letters and numbers.
    constexpr int LETTERS = 26;
    constexpr int NUMBERS = 10;
    
    // BasicRenderer::LETTERS + BasicRenderer::NUMBERS
    constexpr int RENDERER = LETTERS + NUMBERS;
    
    // For use with the initialise() function
    constexpr Uint32 NONE = 0;
    constexpr Uint32 VIDEO = SDL_INIT_VIDEO;
    constexpr Uint32 AUDIO = SDL_INIT_AUDIO;
    constexpr Uint32 NET = ~(
        SDL_INIT_TIMER
        | SDL_INIT_AUDIO
        | SDL_INIT_VIDEO
        | SDL_INIT_JOYSTICK
        | SDL_INIT_HAPTIC
        | SDL_INIT_GAMECONTROLLER
        | SDL_INIT_EVENTS
        | SDL_INIT_NOPARACHUTE
    );
    //}
    
    // Info
    //{
    /**
     * Returns the version in string form.
     */
    std::string version(
        const int* version = VERSION,
        int version_length = VERSION_LENGTH
    ) noexcept {
        std::stringstream stream;
        
        for (int i = 0; i < version_length; i++) {
            stream << version[i];
            
            if (i < version_length - 1) {
                stream << '.';
            }
        }
        
        return stream.str();
    }
    
    /**
     * Returns a string of information about this library.
     */
    std::string info() noexcept {
        std::stringstream stream;
        stream
            << "SDL and SDL Net utilities by Chigozie Agomo.\nVersion: "
            << version()
        ;
        
        return stream.str();
    }
    //}
    
    // Control
    //{
    /**
     * Initialises SDL with the given flags.
     * Optionally intialises SDL_net.
     */
    void initialise(Uint32 flags = VIDEO) noexcept {
        SDL_Init(flags);
        
        if ((flags & NET) == NET) {
            SDLNet_Init();
        }
    }

    /**
     * Shutdowns SDL_net and SDL.
     */
    void terminate() noexcept {
        SDLNet_Quit();
        SDL_Quit();
    }
    
    /**
     * Sends the given command to the command line.
     */
    int command(const std::string& command_string) noexcept {
        return system(command_string.c_str());
    }
    //}
}

/**
 * A class that allows stream insertion syntax to be used with SDL_LogMessage().
 * This class is minimalistic and is designed to be instantiated for each use.
 * Requires manual flushing using Logger::FLUSH.
 */
class Logger {
    public:
        /**
         * An enumeration that defines the log mode.
         */
        enum Mode {
            INFO,
            VERBOSE,
            DEBUG,
            WARNING,
            CRITICAL,
            ERROR
        };
        
        /**
         * Indicates that the output should be flushed.
         * Flushing is not automatic.
         */
        enum Flush {
            FLUSH
        };
        
        /**
         * Defines the log mode.
         */
        Logger(Mode mode = INFO) noexcept {
            switch (mode) {
                case INFO:
                    priority = SDL_LOG_PRIORITY_INFO;
                    break;
                    
                case VERBOSE:
                    priority = SDL_LOG_PRIORITY_VERBOSE;
                    break;
                
                case DEBUG:
                    priority = SDL_LOG_PRIORITY_DEBUG;
                    break;
                
                case WARNING:
                    priority = SDL_LOG_PRIORITY_WARN;
                    break;
                
                case CRITICAL:
                    priority = SDL_LOG_PRIORITY_CRITICAL;
                    break;
                
                case ERROR:
                    priority = SDL_LOG_PRIORITY_ERROR;
                    break;
            }
        }
        
        /**
         * Flushes the output.
         */
        Logger& operator<<(Flush) noexcept {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, priority, "%s", stream.str().c_str());
            stream = std::stringstream();
            return *this;
        }
        
        /**
         * Outputs the passed argument as it would look using std::cout using SDL_LogMessage().
         */
        template<typename T>
        Logger& operator<<(const T& t) noexcept {
            stream << t;
            return *this;
        }
        
    private:
        SDL_LogPriority priority;
        std::stringstream stream;
};
    
/**
 * A namespace for time related functions.
 */
namespace Timer {
    // Constants for converting time bases.
    constexpr double HOURS_TO_MINUTES = 60;
    constexpr double MINUTES_TO_SECONDS = 60;
    
    /**
     * Returns the time in seconds elapsed since the epoch.
     */
    int current() noexcept {
        return time(NULL);
    }
    
    /**
     * Returns the time in seconds.
     * All times returned are relative to each other.
     */
    double time() noexcept {
        return static_cast<std::chrono::duration<double>>(
            std::chrono::steady_clock::now().time_since_epoch()
        ).count();
    }

    /**
     * Halts all functionality in the thread for the
     *   specified amount of time (in seconds).
     */
    void wait(double seconds) noexcept {
        double now = time();
        while (time() < now + seconds);
    }

    /**
     * A constant expression function that converts time from
     *   hours, minutes, and seconds to just seconds.
     */
    constexpr double to_seconds(
        double hours = 0,
        double minutes = 0,
        double seconds = 0
    ) noexcept {
        return
            HOURS_TO_MINUTES * MINUTES_TO_SECONDS * hours
            + MINUTES_TO_SECONDS * minutes
            + seconds
        ;
    }
}

/**
 * A namespace for RNG functions.
 */
namespace Random {
    #define RANDOM_ASSERTION (min > max)
    constexpr const char* RANDOM_ERROR = "min can't be greater than max.";
    
    /**
     * A function that returns a random integer in the interval [min, max].
     * This function is a cross-platform replacement for std::uniform_int_distribution.
     */
    int get_int(std::mt19937& generator, int min, int max) {
        if (RANDOM_ASSERTION) {
            throw std::runtime_error(RANDOM_ERROR);
        }
        
        return min + generator() % static_cast<unsigned>(1 + max - min);
    }
    
    /**
     * A function that returns a random real number in the interval [min, max).
     * This function is a cross-platform replacement for std::uniform_real_distribution.
     */
    double get_real(std::mt19937& generator, double min, double max) {
        if (RANDOM_ASSERTION) {
            throw std::runtime_error(RANDOM_ERROR);
        }
        
        return
            min
            + (max - min)
            * generator()
            / (1 + static_cast<double>(std::numeric_limits<unsigned>::max()))
        ;
    }
    
    /**
     * A function that returns a random real number in the interval [min, max].
     */
    double get_double(std::mt19937& generator, double min, double max) {
        if (RANDOM_ASSERTION) {
            throw std::runtime_error(RANDOM_ERROR);
        }
        
        return
            min
            + (max - min)
            * generator()
            / static_cast<double>(std::numeric_limits<unsigned>::max())
        ;
    }
    
    #undef RANDOM_ASSERTION
}

/**
 * A class that encapsulates the functionality of the Random namespace with an internal generator.
 */
class RNG {
    public:
        /**
         * Seeds the instance with the current time.
         */
        RNG() noexcept:
            generator(Timer::current())
        {}
        
        /**
         * Seeds the instance with the given value.
         */
        RNG(int seed) noexcept:
            generator(seed)
        {}
        
        /**
         * A method that returns a random integer in the interval [min, max].
         * This method is a cross-platform replacement for std::uniform_int_distribution.
         */
        int get_int(int min, int max) {
            return Random::get_int(generator, min, max);
        }
        
        /**
         * A method that returns a random real number in the interval [min, max).
         * This method is a cross-platform replacement for std::uniform_real_distribution.
         */
        double get_real(double min, double max) {
            return Random::get_real(generator, min, max);
        }
        
        /**
         * A method that returns a random real number in the interval [min, max].
         */
        double get_double(double min, double max) {
            return Random::get_double(generator, min, max);
        }
        
    private:
        std::mt19937 generator;
};
//}

// Event Mangement
//{
/**
 * A wrapper class for SDL_Points.
 * Manages a pair of coordinates and its functionality.
 */
class Point {
    public:
        // Constructors and Operator Overloads
        //{
        /**
         * Constructs a new Point instance at the given position.
         */
        Point(int x = 0, int y = 0) noexcept {
            set(x, y);
        }
        
        /**
         * Constructs a new Point instance with the given SDL_Point.
         */
        Point(SDL_Point p) noexcept {
            point = p;
        }
        
        /**
         * Returns true if the coordinates of the given point
         *   match the coordinates of this point.
         */
        bool operator==(const Point& p) const noexcept {
            return point.x == p.point.x && point.y == p.point.y;
        }
        
        /**
         * Returns true if the coordinates of the given
         *   SDL_Point match the coordinates of this point.
         */
        bool operator==(SDL_Point p) const noexcept {
            return point.x == p.x && point.y == p.y;
        }
        
        /**
         * Returns true if the coordinates of the given point
         *   don't match the coordinates of this point.
         */
        bool operator!=(const Point& p) const noexcept {
            return !operator==(p);
        }
        
        /**
         * Returns true if the coordinates of the given SDL_Point
         *   don't match the coordinates of this point.
         */
        bool operator!=(SDL_Point p) const noexcept {
            return !operator==(p);
        }
        
        /**
         * Sets the point with the given SDL_Point.
         */
        Point& operator=(SDL_Point p) noexcept {
            point = p;
            
            return *this;
        }
        //}
        
        // Assignment
        //{
        /**
         * Sets the point to be at the given position.
         */
        void set(int x = 0, int y = 0) noexcept {
            point.x = x;
            point.y = y;
        }
        
        /**
         * Sets the x coordinate.
         */
        void set_x(int x = 0) noexcept {
            point.x = x;
        }
        
        /**
         * Sets the y coordinate.
         */
        void set_y(int y = 0) noexcept {
            point.y = y;
        }
        //}
        
        // Retrieval
        //{
        /**
         * Returns a pointer to the internal SDL_Point.
         */
        const SDL_Point* get() const noexcept {
            return &point;
        }
        
        /**
         * Returns the x coordinate.
         */
        int get_x() const noexcept {
            return point.x;
        }
        
        /**
         * Returns the y coordinate.
         */
        int get_y() const noexcept {
            return point.y;
        }
        //}
        
        // Calculations
        //{
        /**
         * Returns the distance between the given point and this one.
         */
        double get_distance(const Point& p) const noexcept {
            return get_distance(p.point.x, p.point.y);
        }
        
        /**
         * Returns the distnace between the given
         *   coordinates and this one.
         */
        double get_distance(int x = 0, int y = 0) const noexcept {
            return sqrt(
                pow(point.x - x, 2)
                + pow(point.y - y, 2)
            );
        }
        //}
        
        // Event Handling
        //{
        /**
         * Returns true if the mouse button is being clicked.
         * Sets the position of the point to match the mouse's coordinates.
         */
        bool click(int) noexcept;
        
        /**
         * Returns true upon the release of the mouse button being clicked.
         * Halts all thread functionality until the button is released.
         * Sets the position of the point to match the mouse's coordinates.
         */
        bool unclick(int) noexcept;
        //}
        
    private:    
        SDL_Point point; // The internal point
};

/**
 * A namespace for event handling functions.
 * Contains aliases for various mouse buttons and keyboard scan codes.
 * The Event class is the preferred method for event handling, as some platforms require event polling.
 */
namespace Events {
    // Constants
    //{
    // For use with mouse click functions.
    constexpr int LEFT_CLICK = SDL_BUTTON(SDL_BUTTON_LEFT);
    constexpr int MIDDLE_CLICK = SDL_BUTTON(SDL_BUTTON_MIDDLE);
    constexpr int RIGHT_CLICK = SDL_BUTTON(SDL_BUTTON_RIGHT);
    
    // For use with the keyboard press functions.
    constexpr int LETTERS[] = {
        SDL_SCANCODE_A,
        SDL_SCANCODE_B,
        SDL_SCANCODE_C,
        SDL_SCANCODE_D,
        SDL_SCANCODE_E,
        SDL_SCANCODE_F,
        SDL_SCANCODE_G,
        SDL_SCANCODE_H,
        SDL_SCANCODE_I,
        SDL_SCANCODE_J,
        SDL_SCANCODE_K,
        SDL_SCANCODE_L,
        SDL_SCANCODE_M,
        SDL_SCANCODE_N,
        SDL_SCANCODE_O,
        SDL_SCANCODE_P,
        SDL_SCANCODE_Q,
        SDL_SCANCODE_R,
        SDL_SCANCODE_S,
        SDL_SCANCODE_T,
        SDL_SCANCODE_U,
        SDL_SCANCODE_V,
        SDL_SCANCODE_W,
        SDL_SCANCODE_X,
        SDL_SCANCODE_Y,
        SDL_SCANCODE_Z
    };
    
    constexpr int NUMBERS[] = {
        SDL_SCANCODE_0,
        SDL_SCANCODE_1,
        SDL_SCANCODE_2,
        SDL_SCANCODE_3,
        SDL_SCANCODE_4,
        SDL_SCANCODE_5,
        SDL_SCANCODE_6,
        SDL_SCANCODE_7,
        SDL_SCANCODE_8,
        SDL_SCANCODE_9
    };
    
    constexpr int UP = SDL_SCANCODE_UP;
    constexpr int DOWN = SDL_SCANCODE_DOWN;
    constexpr int LEFT = SDL_SCANCODE_LEFT;
    constexpr int RIGHT = SDL_SCANCODE_RIGHT;
    constexpr int ESCAPE = SDL_SCANCODE_ESCAPE;
    constexpr int SPACE = SDL_SCANCODE_SPACE;
    constexpr int BACKSPACE = SDL_SCANCODE_BACKSPACE;
    constexpr int ENTER = SDL_SCANCODE_RETURN;
    constexpr int LEFT_SHIFT = SDL_SCANCODE_LSHIFT;
    constexpr int RIGHT_SHIFT = SDL_SCANCODE_RSHIFT;
    constexpr int MINUS = SDL_SCANCODE_MINUS;
    constexpr int EQUALS = SDL_SCANCODE_EQUALS;
    constexpr int FULL_STOP = SDL_SCANCODE_PERIOD;
    constexpr int COMMA = SDL_SCANCODE_COMMA;
    constexpr int SEMICOLON = SDL_SCANCODE_SEMICOLON;
    constexpr int SLASH = SDL_SCANCODE_SLASH;
    //}
    
    /**
     * Updates the events.
     * Should be called for each event check loop.
     */
    void update() noexcept {
        SDL_PumpEvents();
    }
    
    // Keyboard
    //{
    /**
     * Opens up the virtual keyboard for platforms that offer it.
     */
    void start_keyboard() noexcept {
        SDL_StartTextInput();
    }
    
    /**
     * Closes the keyboard opened by start_keyboard().
     */
    void stop_keyboard() noexcept {
        SDL_StopTextInput();
    }
    
    /**
     * Returns true if the given key is being pressed.
     */
    bool press(int key) noexcept {
        return SDL_GetKeyboardState(nullptr)[key];
    }
    
    /**
     * Returns true upon the release of the given key.
     * All functionality of the thread is halted until
     *   the key is released.
     */
    bool unpress(int key) noexcept {
        // The key press is assumed to be false.
        bool pressed = false;
        
        // If the key was pressed,
        if (press(key)) {
            // the release is waited for
            while (press(key)) {
                update();
            }
            
            // and pressed is set to true.
            pressed = true;
        }
        
        // The key press status is returned.
        return pressed;
    }
    //}
    
    // Mouse
    //{
    /**
     * Returns true if the given mouse button is being clicked.
     */
    bool click(int button = LEFT_CLICK) noexcept {
        return SDL_GetMouseState(nullptr, nullptr) & button;
    }
    
    /**
     * Returns true if the given mouse button is being clicked.
     * Fills in the integers passed with the mouse's coordinates.
     */
    bool click(int button, int& x, int& y) noexcept {
        return SDL_GetMouseState(&x, &y) & button;
    }
    
    /**
     * Returns true if the given mouse button is being clicked.
     * Fills in the Point passed with the mouse's coordinates.
     */
    bool click(int button, Point& point) noexcept {
        int x;
        int y;
        bool state = click(button, x, y);
        point.set(x, y);
        
        return state;
    }
    
    /**
     * Returns true upon the release of the given mouse button.
     * All functionality of the thread is halted until
     *   the button is released.
     * Note that this function will only terminate if the mouse
     *   click is released, which means that subsequent calls
     *   without calling Events::update() will always return false.
     * Store the position of the mouse, in order to
     *   perform multiple mouse position tests.
     */
    bool unclick(int button = LEFT_CLICK) noexcept {
        // The button click is assumed to be false.
        bool clicked = false;
        
        // If the button was clicked,
        if (click(button)) {
            // the release is waited for
            while (click(button)) {
                update();
            }
            
            // and clicked is set to true.
            clicked = true;
        }
        
        // The button click status is returned.
        return clicked;
    }
    
    /**
     * Returns true upon the release of the given mouse button.
     * Fills in the integers passed with the mouse's coordinates.
     * All functionality of the thread is halted until
     *   the button is released.
     * Note that this function will only terminate if the mouse
     *   click is released, which means that subsequent calls
     *   without calling Events::update() will always return false.
     * Store the position of the mouse, in order to
     *   perform multiple mouse position tests.
     */
    bool unclick(int button, int& x, int& y) noexcept {
        // The button click is assumed to be false.
        bool clicked = false;
        
        // If the button was clicked,
        if (click(button)) {
            // the release is waited for
            while (click(button, x, y)) {
                update();
            }
            
            // and clicked is set to true.
            clicked = true;
        }
        
        // The button click status is returned.
        return clicked;
    }
    
    /**
     * Returns true upon the release of the given mouse button.
     * Fills in the Point passed with the mouse's coordinates.
     * All functionality of the thread is halted until
     *   the button is released.
     * Note that this function will only terminate if the mouse
     *   click is released, which means that subsequent calls
     *   without calling Events::update() will always return false.
     * Store the position of the mouse, in order to
     *   perform multiple mouse position tests.
     */
    bool unclick(int button, Point& point) noexcept {
        int x;
        int y;
        bool state = unclick(button, x, y);
        point.set(x, y);
        
        return state;
    }
    //}
    
    // Clipbaord
    //{
    void set_clipboard(const std::string& string) {
        if (SDL_SetClipboardText(string.c_str())) {
            throw std::runtime_error(SDL_GetError());
        }
    }
    
    std::string get_clipboard() noexcept {
        char* clipboard = SDL_GetClipboardText();
        std::string string(clipboard);
        SDL_free(clipboard);
        return string;
    }
    //}
}

// Point Event Handling
//{
/**
 * Returns true if the mouse button is being clicked.
 * Sets the position of the point to match the mouse's coordinates.
 */
bool Point::click(int button = Events::LEFT_CLICK) noexcept {
    return Events::click(button, *this);
}

/**
 * Returns true upon the release of the mouse button being clicked.
 * Halts all thread functionality until the button is released.
 * Sets the position of the point to match the mouse's coordinates.
 */
bool Point::unclick(int button = Events::LEFT_CLICK) noexcept {
    return Events::unclick(button, *this);
}
//}

/**
 * A class that defines an event.
 * This is the preferred method for event handling, as some platforms require event polling.
 */
class Event {
    public:
        /**
         * Defines different types of event.
         */
        enum Type {
            MISCELLANEOUS,
            TERMINATE,
            KEY_PRESS,
            KEY_RELEASE,
            MOUSE_MOTION,
            LEFT_CLICK,
            LEFT_UNCLICK,
            MIDDLE_CLICK,
            MIDDLE_UNCLICK,
            RIGHT_CLICK,
            RIGHT_UNCLICK,
            SCROLL,
            RESIZE
        };
        
        /**
         * Creates an uninitialised event.
         */
        Event() noexcept {}
        
        // Polling
        //{
        /**
         * Sets the event to the oldest event in the event queue.
         * The event is removed.
         * Returns false if the event queue is empty.
         */
        bool poll() noexcept {
            bool pending = SDL_PollEvent(&event);
            type_ = determine();
            
            return pending;
        }
        
        /**
         * Sets the event to the oldest event in the event queue.
         * The event is removed.
         * Halts thread execution while the event queue is empty.
         * Throws an exception upon error.
         * Provides very poor performance with many events in quick succession.
         * For this reason, poll() is preferred in most circumstances.
         */
        void wait() {
            bool error = !SDL_WaitEvent(&event);
            
            if (error) {
                throw std::runtime_error(SDL_GetError());
            }
            
            type_ = determine();
        }
        
        /**
         * Sets the event to the oldest event in the event queue.
         * The event is removed.
         * Halts thread execution while the event queue is
         *   empty for the time given (in milliseconds).
         * Returns false if time ran out or an error occurred.
         * Provides very poor performance with many events in quick succession.
         * For this reason, poll() is preferred in most circumstances.
         */
        bool timed_wait(int ms) noexcept {
            bool pending = SDL_WaitEventTimeout(&event, ms);
            type_ = determine();
            
            return pending;
        }
        //}
        
        // Queries
        //{
        /**
         * Returns the type of event.
         */
        Type type() const noexcept {
            return type_;
        }
        
        /**
         * Returns the key of the keyboard event.
         */
        int key() const noexcept {
            return event.key.keysym.scancode;
        }
        
        /**
         * Returns the relative position of the mouse since the last motion.
         */
        Point motion() const noexcept {
            return Point(event.motion.xrel, event.motion.yrel);
        }
        
        /**
         * Returns the relative scroll of the mouse wheel.
         */
        Point scroll() const noexcept {
            int normal = event.wheel.direction == SDL_MOUSEWHEEL_NORMAL ? 1 : -1;
            
            return Point(normal * event.wheel.x, normal * event.wheel.y);
        }
        
        /**
         * Returns the coordinates of a motion event.
         */
        Point motion_position() const noexcept {
            return Point(event.motion.x, event.motion.y);
        }
        
        /**
         * Returns the coordinates of a click/unclick event.
         */
        Point click_position() const noexcept {
            return Point(event.button.x, event.button.y);
        }
        
        /**
         * Returns the window's new width.
         */
        int window_width() const noexcept {
            return event.window.data1;
        }
        
        /**
         * Returns the window's new height.
         */
        int window_height() const noexcept {
            return event.window.data2;
        }
        //}
        
    private:
        /**
         * Determines the event's type.
         */
        Type determine() const noexcept {
            switch (event.type) {
                case SDL_WINDOWEVENT:
                    switch (event.window.event) {
                        case SDL_WINDOWEVENT_CLOSE:
                            return TERMINATE;
                        
                        case SDL_WINDOWEVENT_SIZE_CHANGED:
                            return RESIZE;
                        
                        default:
                            return MISCELLANEOUS;
                    }
                
                case SDL_KEYDOWN:
                    return KEY_PRESS;
                    
                case SDL_KEYUP:
                    return KEY_RELEASE;
                
                case SDL_MOUSEMOTION:
                    return MOUSE_MOTION;
                
                case SDL_MOUSEBUTTONDOWN:
                    switch (event.button.button) {
                        case SDL_BUTTON_LEFT:
                            return LEFT_CLICK;
                        
                        case SDL_BUTTON_MIDDLE:
                            return MIDDLE_CLICK;
                        
                        case SDL_BUTTON_RIGHT:
                            return RIGHT_CLICK;
                        
                        default:
                            return MISCELLANEOUS;
                    }
                
                case SDL_MOUSEBUTTONUP:
                    switch (event.button.button) {
                        case SDL_BUTTON_LEFT:
                            return LEFT_UNCLICK;
                        
                        case SDL_BUTTON_MIDDLE:
                            return MIDDLE_UNCLICK;
                        
                        case SDL_BUTTON_RIGHT:
                            return RIGHT_UNCLICK;
                        
                        default:
                            return MISCELLANEOUS;
                    }
                
                case SDL_MOUSEWHEEL:
                    return SCROLL;
                
                default:
                    return MISCELLANEOUS;
            }
        }
        
        SDL_Event event; // The internal SDL Event.
        Type type_; // The type of event.
};
//}

// Messenger Classes
//{
/**
 * An abstract class for the two types of TCP messengers
 *   to inherit from.
 * This class cannot and should not be instantiated.
 */
class Messenger {
    public:
        /**
         * Sends the string passed to the other messenger.
         * The string is padded to be of a specific length.
         */
        void send(std::string message, int length = -1) const {
            // If the socket has not been initialised, an exception is thrown.
            if (!socket) {
                throw std::runtime_error("Uninitialised socket.");
            }
            
            // If the string's length is unspecified or invalid, the default length is used.
            if (length < 0) {
                length = padding;
            }
            
            // The message is padded to match the given length - 1.
            // length - 1, because c_str() appends the string with '\0' for the full length.
            if (length > message.length() + 1) {
                message += std::string(length - message.length() - 1, padder);
            }
            
            // The message is sent in byte form.
            SDLNet_TCP_Send(socket, message.c_str(), length);
        }
        
        /**
         * Receives a string from the other messenger.
         * A maximum number of bytes, equal to buffer_size, is read.
         * Uses C-style strings internally, so buffer_size should
         *   be one greater than the length of the C++ string sent.
         */
        std::string read(int buffer_size = DEFAULT_READ) const {
            // If the socket has not been initialised, an exception is thrown.
            if (!socket) {
                throw std::runtime_error("Uninitialised socket.");
            }
            
            // A vector is used to store the received message.
            std::vector<char> buffer(buffer_size);
            
            // The message is received and stored in the vector.
            SDLNet_TCP_Recv(socket, buffer.data(), buffer_size);
            
            // A C++ string is formed from the received message and returned.
            return std::string(buffer.data());
        }

        static constexpr int DEFAULT_READ = 1000; // Default max for read().
        static constexpr int DEFAULT_PADDING = DEFAULT_READ; // Default min for send().
        static constexpr char DEFAULT_PADDER = '\0'; // Default padder for send().
        
    protected:
        /**
         * Sets the padding width and the character used for padding.
         */
        Messenger(int padding = DEFAULT_PADDING, char padder = DEFAULT_PADDER) noexcept:
            padding(padding),
            padder(padder)
        {}
        
        TCPsocket socket = nullptr;  // The TCP socket used for the connection.
        int padding; // The minimum width of messages sent by default.
        char padder; // The character used to pad the messages sent.
};

/**
 * A Messenger subclass for the server.
 */
class Server: public virtual Messenger {
    public:
        /**
         * Constructs an uninitialised Server to be initialised later.
         */
        Server() noexcept {}
    
        /**
         * Constructs a new TCP messenger for the server.
         * The server is hosted at localhost:[port].
         * This constructor will throw if the port cannot be opened
         *   or the construction was cancelled in another thread.
         */
        Server(
            int port,
            const bool& cancel = false,
            int padding = DEFAULT_PADDING,
            char padder = DEFAULT_PADDER
        ):
            Messenger(padding, padder)
        {
            IPaddress ip_address;
            SDLNet_ResolveHost(&ip_address, nullptr, port);
            
            // If the port cannot be opened, an exception is thrown.
            if (!(server = SDLNet_TCP_Open(&ip_address))) {
                throw std::runtime_error(SDL_GetError());
            }
            
            // Halts the thread execution until the client connects.
            // If cancel is true, an exception is thrown.
            // This exception can allow for the Server construcion to be cancelled.
            while (!(socket = SDLNet_TCP_Accept(server))) {
                if (cancel) {
                    SDLNet_TCP_Close(server);
                    throw std::runtime_error("The server construction was cancelled.");
                }
            }
            
            allocated = true;
        }
        
        /**
         * Instances of this class are not safe to copy.
         */
        Server(const Server&) = delete;
        
        /**
         * Instances of this class are safe to move.
         * Previously opened sockets are closed.
         */
        Server(Server&& s) noexcept {
            operator=(std::move(s));
        }
        
        
        /**
         * Closes the TCP sockets associated with the messenger.
         */
        ~Server() noexcept {
            close_sockets();
        }
        
        /**
         * Instances of this class are not safe to copy.
         */
        Server& operator=(const Server&) = delete;
        
        /**
         * Instances of this class are safe to move.
         * Previously opened sockets are closed.
         */
        Server& operator=(Server&& s) noexcept {
            close_sockets();
            server = s.server;
            socket = s.socket;
            allocated = s.allocated;
            s.allocated = false;
            
            return *this;
        }
        
        /**
         * Returns a vector of up to 100 strings representing the possible IP addresses that the Server may use.
         */
        static std::vector<std::string> get_default_addresses() noexcept {
            std::array<IPaddress, MAX_ADDRESSES> addresses;
            int count = SDLNet_GetLocalAddresses(&addresses[0], MAX_ADDRESSES);
            std::vector<std::string> strings(count);
            
            for (int i = 0; i < count; ++i) {
                Uint32 d = addresses[i].host;
                Uint32 a = d % 256;
                d /= 256;
                Uint32 b = d % 256;
                d /= 256;
                Uint32 c = d % 256;
                d /= 256;
                
                strings[i] =
                    std::to_string(a) + "."
                    + std::to_string(b) + "."
                    + std::to_string(c) + "."
                    + std::to_string(d)
                ;
            }
            
            return strings;
        }
        
        static constexpr int MAX_ADDRESSES = 100;

    private:
        /**
         * Closes the TCP sockets associated with the messenger.
         */
        void close_sockets() noexcept {
            if (allocated) {
                SDLNet_TCP_Close(socket);
                SDLNet_TCP_Close(server);
            }
        }
        
        TCPsocket server = nullptr; // The TCP socket used for to accept the client.
        bool allocated = false; // True if the sockets should be closed by this instance.
};

/**
 * A Messenger subclass for the client.
 */
class Client: public virtual Messenger {
    public:
        /**
         * Constructs an uninitialised Client to be initialised later.
         */
        Client() noexcept {}
        
        /**
         * Constructs a new TCP messenger for the client.
         * The client connects to the server at [address]:[port].
         */
        Client(
            const std::string& address,
            int port,
            int padding = DEFAULT_PADDING,
            char padder = DEFAULT_PADDER
        ) {
            IPaddress ip_address;
            
            // The constructor throws if the the server cannot be connected to.
            if (
                SDLNet_ResolveHost(&ip_address, address.c_str(), port)
                || !(socket = SDLNet_TCP_Open(&ip_address))
            ) {
                throw std::runtime_error(SDL_GetError());
            }
            
            allocated = true;
        }
        
        /**
         * Instances of this class are not safe to copy.
         */
        Client(const Client&) = delete;
        
        /**
         * Instances of this class are safe to move.
         * Previously opened sockets are closed.
         */
        Client(Client&& client) noexcept {
            operator=(std::move(client));
        }
        
        /**
         * Closes the TCP socket associated with the messenger.
         */
        ~Client() noexcept {
            close_socket();
        }

        /**
         * Instances of this class are not safe to copy.
         */
        Client& operator=(const Client&) = delete;
        
        /**
         * Instances of this class are safe to move.
         * Previously opened sockets are closed.
         */
        Client& operator=(Client&& client) {
            close_socket();
            socket = client.socket;
            allocated = client.allocated;
            client.allocated = false;
            
            return *this;
        }
        
    private:
        /**
         * Closes the TCP socket associated with the messenger.
         */
        void close_socket() {
            if (allocated) {
                SDLNet_TCP_Close(socket);
            }
        }
        
        bool allocated = false; // True if the socket should be closed by this instance.
};

/**
 * A class that allows one to receive a message in another thread.
 * MessengerThread contains an instance of this class and its subclasses should be used instead.
 */
class MessengerPackage {
    public:
        /**
         * Takes the messenger, the string to overwrite, and the
         *   maximum string length to construct a thread package.
         */
        MessengerPackage(
            const Messenger& m,
            std::string& s,
            int l = Messenger::DEFAULT_READ
        ) noexcept:
            messenger(m),
            string(s),
            length(l)
        {}
        
        /**
         * Returns the messenger.
         */
        const Messenger& get_messenger() const noexcept {
            return messenger;
        }
        
        /**
         * Returns the modifiable string.
         */
        std::string& get_string() noexcept {
            return string;
        }
        
        /**
         * Returns a constant reference to the string.
         */
        const std::string& get_string() const noexcept {
            return string;
        }
        
        /**
         * Returns the string's maximum length.
         */
        int get_length() const noexcept {
            return length;
        }
        
        /**
         * A static method suitable for use with the Thread class.
         * This method receives a single string from the connected
         *   messenger, overwrites the given string with it, and returns.
         */
        static int get_message(void* data) noexcept {
            // The thread package is extracted.
            MessengerPackage& package = *static_cast<MessengerPackage*>(data);
            const Messenger& messenger = package.get_messenger();
            std::string& string = package.get_string();
            int length = package.get_length();
            
            // The string's contents are updated with the received string.
            string = messenger.read(length);
            
            return 0;
        }
        
    private:
        const Messenger& messenger; // The messenger to read with.
        std::string& string;        // The string to overwrite.
        int length;                 // The maximum number of characters to be read.
};

/**
 * A class that can be used to conditionally instantiate a server in another thread.
 * ServerThread contains an instance of this class and should be used instead.
 */
class ServerPackage {
    public:
        /**
         * Constructs a server package with the unique pointer to the server,
         *   the cancellation boolean, and the port number.
         */
        ServerPackage(std::unique_ptr<Server>& s, bool& c, int p) noexcept:
            server(s),
            cancel(c),
            port(p)
        {}
        
        /**
         * Returns a reference to the server's unique pointer.
         */
        std::unique_ptr<Server>& get_server() noexcept {
            return server;
        }
        
        /**
         * Returns a reference to the boolean value.
         */
        bool& get_cancel() noexcept {
            return cancel;
        }
        
        /**
         * Returns the port that the server should be hosted on.
         */
        int get_port() const noexcept {
            return port;
        }
        
        /**
         * A static method suitable for use with the Thread class.
         * This method attempts to construct a Server instance
         *   and store it in the unique pointer.
         * However, the construction will terminate if the
         *   cancellation boolean's value is set to true.
         * The construction will also fail if the port could not be opened.
         */
        static int make_server(void* data) noexcept {
            // The thread package is extracted.
            ServerPackage& package = *static_cast<ServerPackage*>(data);
            std::unique_ptr<Server>& server = package.get_server();
            bool& cancel = package.get_cancel();
            int port = package.get_port();
            
            // The construction is attempted.
            try {
                server = std::make_unique<Server>(port, cancel);
            }
            
            // The user is notified that the constructor threw.
            catch (const std::exception& exception) {
                cancel = true;
                return -1;
            }
            
            // Zero is returned for a successful construction.
            return 0;
        }
    
    private:
        std::unique_ptr<Server>& server; // The server.
        bool& cancel; // True if the server's construction should be cancelled.
        int port; // The port that the server should be hosted on.
};

/**
 * A class that allow two messengers to act as a
 *   bridge for two other messengers in another thread.
 * One messenger should be connected to the source and
 *   the other should be connected to the destination.
 * This class can allow two Client instances to communicate through
 *   two Server instances, which can be useful if the two parties
 *   are unable to perform port forwarding (but a third party is able to).
 * BridgeThread contains an instance of this class and should be used instead.
 */
class Bridge {
    public:
        /**
         * Takes constant references to the messengers forming the bridge.
         * Also takes a string, which will terminate the thread static
         *   method, if the source sends it to the destination.
         */
        Bridge(
            const Messenger& s,
            const Messenger& d,
            const std::string& t
        ) noexcept:
            source(s),
            destination(d),
            terminator(t)
        {}
        
        /**
         * Returns a constant reference to the source messenger.
         */
        const Messenger& get_source() const noexcept {
            return source;
        }
        
        /**
         * Returns a constant reference to the destination messenger.
         */
        const Messenger& get_destination() const noexcept {
            return destination;
        }
        
        /**
         * Returns the terminator string.
         */
        const std::string& get_terminator() const noexcept {
            return terminator;
        }
        
        /**
         * Forms a one-way bridge from the source to the destination.
         * Terminates if the terminator string is passed
         *   from the source to the destination.
         */
        static int make_bridge(void* data) noexcept {
            // The package is extracted.
            Bridge& package = *static_cast<Bridge*>(data);
            const Messenger& source = package.get_source();
            const Messenger& destination = package.get_destination();
            std::string terminator(package.get_terminator());
            std::string message;
            
            // The message is sent before checking for termination.
            while (message != terminator) {
                message = source.read();
                destination.send(message);
            }
            
            return 0;
        }
        
    private:
        const Messenger& source;      // The messenger connected to the source.
        const Messenger& destination; // The messenger connected to the destination.
        std::string terminator;       // The string that terminates the thread.
};
//}

// Shape Classes
//{
/**
 * An abstract base class for shapes to inherit from.
 * All shapes must have the ability to state if they contain
 *   a given Point, which also allowed them to state if they
 *   are being clicked.
 */
class Shape {
    public:
        /**
         * Returns true if the Point is contained within the shape.
         */
        virtual bool contains(const Point&) const noexcept = 0;
        
        /**
         * Returns true if the given mouse button is being clicked and
         *   the position of the mouse is contained within the shape.
         */
        bool click(int button = Events::LEFT_CLICK) const noexcept {
            Point mouse;
            
            return mouse.click(button) && contains(mouse);
        }
        
        /**
         * Returns true upon the release of the given mouse
         *   button in the bounds of the shape, if the click was
         *   in the bounds of the shape to begin with.
         * Halts all functionality of the thread until
         *   the mouse button is released.
         * Note that this method will only terminate if the mouse
         *   click is released, which means that subsequent calls for the same shape
         *   without calling Events::update() will always return false.
         */
        bool unclick(int button = Events::LEFT_CLICK) const noexcept {
            Point mouse;
            
            return
                click(button)
                && mouse.unclick(button)
                && contains(mouse)
            ;
        }
};

/**
 * A wrapper class for the SDL_Rect.
 * Manages a pair of coordinates, a pair of dimensions,
 *   and their functionality.
 */
class Rectangle: public Shape {
    public:
        // Constructors
        //{
        /**
         * Constructs a new Rectangle with
         *   the given position and dimensions.
         */
        Rectangle(int x = 0, int y = 0, int w = 0, int h = 0) noexcept {
            set(x, y, w, h);
        }
        
        /**
         * Constructs a new Rectangle with its top-left vertex
         *   in the same position of the given point.
         * The rectangle's dimensions are determined by the given arguments.
         */
        Rectangle(const Point& point, int width = 0, int height = 0) noexcept {
            set(point.get_x(), point.get_y(), width, height);
        }
        
        /**
         * Constructs a minimally sized Rectangle that
         *    contains the two points given.
         */
        Rectangle(const Point& point_0, const Point& point_1) noexcept {
            int x_0 = point_0.get_x();
            int y_0 = point_0.get_y();
            int x_1 = point_1.get_x();
            int y_1 = point_1.get_y();
            
            set(
                x_0 < x_1 ? x_0 : x_1,
                y_0 < y_1 ? y_0 : y_1,
                abs(x_0 - x_1) + 1,
                abs(y_0 - y_1) + 1
            );
        }
        
        /**
         * Constructs a new Rectangle with the given SDL_Rect.
         */
        Rectangle(SDL_Rect r) noexcept {
            rectangle = r;
        }
        //}
        
        // Operator Overloads
        //{
        /**
         * Sets this object to cover the exact same area
         *   as the given SDL_Rect.
         */
        Rectangle& operator=(SDL_Rect r) noexcept {
            rectangle = r;
            
            return *this;
        }
        
        /**
         * Returns true if the given rectangle covers
         *   the exact same area as this one.
         */
        bool operator==(const Rectangle& r) const noexcept {
            return SDL_RectEquals(&rectangle, &r.rectangle);
        }
        
        /**
         * Returns true if the given SDL_Rect covers
         *   the exact same area as this one.
         */
        bool operator==(SDL_Rect r) const noexcept {
            return SDL_RectEquals(&rectangle, &r);
        }
        
        /**
         * Returns true if the given rectangle doesn't
         *   cover the exact same area as this one.
         */
        bool operator!=(const Rectangle& r) const noexcept {
            return !operator==(r);
        }
        
        /**
         * Returns true if the given SDL_Rect doesn't
         *   cover the exact same area as this one.
         */
        bool operator!=(SDL_Rect r) const noexcept {
            return !operator==(r);
        }
        //}
        
        /**
         * Returns a pointer to the internal SDL_Rect.
         */
        const SDL_Rect* get() const noexcept {
            return &rectangle;
        }
        
        // Dimension Retrieval
        //{
        /**
         * Returns the left edge's position.
         */
        int get_x() const noexcept {
            return rectangle.x;
        }
        
        /**
         * Returns the top edge's position.
         */
        int get_y() const noexcept {
            return rectangle.y;
        }
        
        /**
         * Returns the rectangle's width.
         */
        int get_width() const noexcept {
            return rectangle.w;
        }
        
        /**
         * Returns the rectangle's height.
         */
        int get_height() const noexcept {
            return rectangle.h;
        }
        
        /**
         * Constructs and returns a Point at the Rectangle's
         * top-left vertex.
         */
        Point get_point() const noexcept {
            return Point(rectangle.x, rectangle.y);
        }
        //}
        
        // Dimension Assignment
        //{
        /**
         * Sets the position and dimensions of this Rectangle.
         */
        void set(int x = 0, int y = 0, int w = 0, int h = 0) noexcept {
            rectangle.x = x;
            rectangle.y = y;
            rectangle.w = w;
            rectangle.h = h;
        }
        
        /**
         * Sets the rectangle's position according to the same rules as
         *   Sprite::blit(const Surface&, double, double).
         * The width and height should correspond to the width
         *   and height of the template sprite.
         * Uses the given sprite as a template for this.
         */
        void set(int width, int height, double x = 0.5, double y = 0.5) noexcept {
            rectangle.x = x * width - rectangle.w / 2;
            rectangle.y = y * height - rectangle.h / 2;
        }
        
        /**
         * Sets the left edge's position of the rectangle.
         */
        void set_x(int x = 0) noexcept {
            rectangle.x = x;
        }
        
        /**
         * Sets the top edge's position of the rectangle.
         */
        void set_y(int y = 0) noexcept {
            rectangle.y = y;
        }
        
        /**
         * Sets the width of the rectangle.
         */
        void set_width(int width = 0) noexcept {
            rectangle.w = width;
        }
        
        /**
         * Sets the height of the rectangle.
         */
        void set_height(int height = 0) noexcept {
            rectangle.h = height;
        }
        //}
        
        // Dimension Modification
        //{
        /**
         * Moves the rectangle according to the given arguments.
         * Positive values of x move the rectangle to the right.
         * Negative values of x move the rectangle to the left.
         * Positive values of y move the rectangle downwards.
         * Negative values of y move the rectangle upwards.
         */
        void shift(int x = 0, int y = 0) noexcept {
            rectangle.x += x;
            rectangle.y += y;
        }
        
        /**
         * Changes the dimensions of the rectangle according to the given arguments.
         * Positive values increase the dimension.
         * Negative values decrease the dimension.
         */
        void widen(int width = 0, int height = 0) noexcept {
            rectangle.w += width;
            rectangle.h += height;
        }
        //}
        
        // Geometry Tests
        //{
        /**
         * Returns true if the given point is inside
         *   of this rectangle.
         */
        bool contains(const Point& point) const noexcept override {
            return SDL_PointInRect(point.get(), &rectangle);
        }
        
        /**
         * Returns true if the given rectangle
         *   intersects with this one.
         */
        bool intersects(const Rectangle& r) const noexcept {
            return SDL_HasIntersection(&r.rectangle, &rectangle);
        }
        //}
        
    private:
        SDL_Rect rectangle; // The internal rectangle
};

/**
 * A class derived from Shape to represent a circle.
 */
class Circle: public Shape {
    public:
        // Constructors and Operator Overloads
        //{
        /**
         * Constructs a circle at the given coordinates
         *   and with the given radius.
         */
        Circle(int x = 0, int y = 0, int r = 0) noexcept: point(x, y) {
            radius = r;
        }
        
        /**
         * Constructs a circle at the given point
         *   with the given radius.
         */
        Circle(const Point& p, int r = 0) noexcept: point(p) {
            radius = r;
        }
        
        /**
         * Returns true if the given circle covers
         *   the same area as this one.
         */
        bool operator==(const Circle& c) const noexcept {
            return point == c.point && radius == c.radius;
        }
        
        /**
         * Returns true if the given circle doesn't
         *   cover the same are as this one.
         */
        bool operator!=(const Circle& c) const noexcept {
            return !operator==(c);
        }
        //}
        
        // Dimension Assignment
        //{
        /**
         * Sets the circle's position and radius.
         */
        void set(int x, int y, int r) noexcept {
            set(x, y);
            radius = r;
        }
        
        /**
         * Sets the circle's position and radius.
         */
        void set(const Point& p, int r = 0) noexcept {
            point = p;
            radius = r;
        }
        
        /**
         * Sets the circle's position.
         */
        void set(int x, int y) noexcept {
            set_x(x);
            set_y(y);
        }
        
        /**
         * Sets the circle's position.
         */
        void set(const Point& p) noexcept {
            point = p;
        }
        
        /**
         * Sets the circle's x coordinate.
         */
        void set_x(int x = 0) noexcept {
            point.set_x(x);
        }
        
        /**
         * Sets the circle's y coordinate.
         */
        void set_y(int y = 0) noexcept {
            point.set_y(y);
        }
        
        /**
         * Sets the circle's radius.
         */
        void set_radius(int r = 0) noexcept {
            radius = r;
        }
        //}
        
        // Dimension Retrieval
        //{
        /**
         * Returns a reference to the circle's Point instance.
         */
        Point& get_point() noexcept {
            return point;
        }
        
        /**
         * Returns the circle's x coordinate.
         */
        int get_x() const noexcept {
            return point.get_x();
        }
        
        /**
         * Returns the circle's y coordinate.
         */
        int get_y() const noexcept {
            return point.get_y();
        }
        
        /**
         * Returns the circle's radius.
         */
        int get_radius() const noexcept {
            return radius;
        }
        //}
        
        /**
         * Returns true if the given Point is contained within the circle.
         */
        bool contains(const Point& p) const noexcept override {
            return point.get_distance(p) <= radius;
        }
        
    private:
        Point point; // The centre of the circle.
        int radius;  // The radius of the circle.
};
//}

// Video and Audio Classes
//{
/**
 * A wrapper class for SDL_Surfaces.
 * Manages the blitting of one surface to another.
 * Also allows for the surface or a rectangular section
 *   of it to be filled in with a single colour.
 * Instances of this class are not copiable, but are movable.
 */
class Sprite {
    public:
        /**
         * An enumeration of various predefined colours.
         * Used with the sprite filling methods.
         */
        enum Colour {
            BLACK,   // 000000
            GREY,    // 7f7f7f
            WHITE,   // ffffff
            RED,     // ff0000
            YELLOW,  // ffff00
            GREEN,   // 00ff00
            CYAN,    // 00ffff
            BLUE,    // 0000ff
            MAGENTA  // ff00ff
        };
        
        // Constructors
        //{
        /**
         * Constructs a new Sprite object using the given surface.
         */
        Sprite(SDL_Surface* surf) noexcept {
            surface = surf;
        }
        
        /**
         * Constructs a new Sprite object.
         * The Sprite is created with the given dimenions.
         */
        Sprite(int width = 0, int height = 0) noexcept {
            create_surface(width, height);
        }
        
        /**
         * Constructs a new Sprite object.
         * The Sprite is created with the given dimenions.
         * The Sprite is filled in with the given colour.
         */
        Sprite(int width, int height, int red, int green, int blue) noexcept {
            create_surface(width, height);
            fill(red, green, blue);
        }
        
        /**
         * Constructs a new Sprite object.
         * The Sprite is created with the given dimenions.
         * The Sprite is filled in with the given greyscale shade.
         */
        Sprite(int width, int height, int brightness) noexcept {
            create_surface(width, height);
            fill(brightness, brightness, brightness);
        }
        
        /**
         * Constructs a new Sprite object.
         * The Sprite is created with the given dimenions.
         * The Sprite is filled in with the given colour.
         * Uses predefined colours.
         */
        Sprite(int width, int height, Colour colour) noexcept {
            create_surface(width, height);
            fill(colour);
        }
        
        /**
         * Constructs a new Sprite object.
         * The Sprite is loaded from the BMP file passed in
         *   string form and is not scaled.
         */
        Sprite(const std::string& source) {
            surface = SDL_LoadBMP(source.c_str());
            
            // An exception is thrown, if the surface couldn't be loaded.
            if (!surface) {
                throw std::runtime_error(SDL_GetError());
            }
            
            allocated = true;
        }
        
        /**
         * Constructs a new Sprite object.
         * The Sprite is loaded from the BMP file passed in
         *   string form and scaled to the given dimensions.
         */
        Sprite(const std::string& source, int width, int height) {
            SDL_Surface* raw_surface = SDL_LoadBMP(source.c_str());
            
            // An exception is thrown, if the surface couldn't be loaded.
            if (!raw_surface) {
                throw std::runtime_error(SDL_GetError());
            }
            
            create_surface(width, height);
            SDL_BlitScaled(raw_surface, nullptr, surface, nullptr);
            SDL_FreeSurface(raw_surface);
        }
        
        /**
         * Constructs a new Sprite object.
         * The Sprite is loaded from the BMP file passed in
         *   string form and scaled to the given dimensions.
         * The size of the sprite is a ratio of the given sprite.
         */
        Sprite(
            const std::string& source,
            const Sprite& stemplate,
            double width,
            double height
        ):
            Sprite(
                source,
                width * stemplate.width(),
                height * stemplate.height()
            )
        {}
        
        /**
         * Copying a sprite can be done safely using blitting.
         */
        Sprite(const Sprite& sprite) noexcept {
            operator=(sprite);
        }
        
        /**
         * Sprites can be moved safely.
         */
        Sprite(Sprite&& sprite) noexcept {
            operator=(std::move(sprite));
        }
        //}
        
        /**
         * Frees the mmeory dynamically allocated to the surface
         *   if it was allocated in this class.
         */
        ~Sprite() noexcept {
            destroy_surface();
        }
        
        // Assignment
        //{
        /**
         * Initialises the sprite with the given surface.
         */
        Sprite& operator=(SDL_Surface* surf) noexcept {
            destroy_surface();
            surface = surf;
            
            return *this;
        }
        
        /**
         * Copying a sprite can be done safely using blitting.
         */
        Sprite& operator=(const Sprite& sprite) noexcept {
            create_surface(sprite.surface->w, sprite.surface->h);
            blit(sprite, 0, 0);
            
            return *this;
        }
        
        /**
         * Sprites can be moved safely.
         */
        Sprite& operator=(Sprite&& sprite) noexcept {
            destroy_surface();
            surface = sprite.surface;
            allocated = sprite.allocated;
            sprite.allocated = false;
            
            return *this;
        }
        //}
        
        // Size Queries
        //{
        /**
         * Returns the width of the sprite.
         */
        int width() const noexcept {
            return get_width();
        }
         
        /**
         * Returns the height of the sprite.
         */
        int height() const noexcept {
            return get_height();
        }
        
        /**
         * Returns the width of the sprite.
         */
        int get_width() const noexcept {
            return surface->w;
        }
        
        /**
         * Returns the height of the sprite.
         */
        int get_height() const noexcept {
            return surface->h;
        }
        //}
        
        // Colour Fill
        //{
        /**
         * Fills in the sprite with the given RGB colour.
         */
        void fill(int red, int green, int blue) noexcept {
            SDL_FillRect(
                surface, nullptr,
                SDL_MapRGB(surface->format, red, green, blue)
            );
        }
        
        /**
         * Fills in the sprite with a grayscale shade.
         */
        void fill(int brightness) noexcept {
            fill(brightness, brightness, brightness);
        }
        
        /**
         * Fills in the sprite with a predefined colour.
         */
        void fill(Colour colour = BLACK) noexcept {
            std::array<int, 3> rgb = to_rgb(colour);
            fill(rgb[0], rgb[1], rgb[2]);
        }
        
        /**
         * Fills in the sprite in the area defined by the given rectangle.
         */
        void fill(const Rectangle& rectangle, int red, int green, int blue) noexcept {
            SDL_FillRect(
                surface, rectangle.get(),
                SDL_MapRGB(surface->format, red, green, blue)
            );
        }
        
        /**
         * Fills in the sprite in the area defined by the given rectangle.
         * The sprite is filled in with a grayscale shade.
         */
        void fill(const Rectangle& rectangle, int brightness) noexcept {
            fill(rectangle, brightness, brightness, brightness);
        }
        
        /**
         * Fills in the sprite in the area defined by the given rectangle.
         * Uses predefined colours.
         */
        void fill(const Rectangle& rectangle, Colour colour = BLACK) noexcept {
            std::array<int, 3> rgb = to_rgb(colour);
            fill(rectangle, rgb[0], rgb[1], rgb[2]);
        }
        
        /**
         * Fills in the sprite in the area defined by the given shape.
         */
        void fill(const Shape& shape, int red, int green, int blue) noexcept {
            for (int i = 0; i < surface->w; i++) {
                for (int j = 0; j < surface->h; j++) {
                    Rectangle rectangle(i, j, 1, 1);
                    
                    if (shape.contains(rectangle.get_point())) {
                        fill(rectangle, red, green, blue);
                    }
                }
            }
        }
        
        /**
         * Fills in the sprite in the area defined by the given shape.
         * The sprite is filled in with a grayscale shade.
         */
        void fill(const Shape& shape, int brightness) noexcept {
            fill(shape, brightness, brightness, brightness);
        }
        
        /**
         * Fills in the sprite in the area defined by the given shape.
         * Uses predefined colours.
         */
        void fill(const Shape& shape, Colour colour = BLACK) noexcept {
            std::array<int, 3> rgb = to_rgb(colour);
            fill(shape, rgb[0], rgb[1], rgb[2]);
        }
        //}
        
        // Blitting
        //{
        /**
         * Blits the given sprite to this one.
         * The given sprite is scaled to match the size of this one.
         */
        void blit(const Sprite& sprite) noexcept {
            SDL_BlitScaled(sprite.surface, nullptr, surface, nullptr);
        }
        
        /**
         * Blits the given sprite to this one.
         * The top-left corner of the given sprite is blitted to
         *   the co-ordinates given.
         * No scaling is performed.
         */
        void blit(const Sprite& sprite, int x, int y) noexcept {
            SDL_Rect rectangle;
            rectangle.x = x;
            rectangle.y = y;
            SDL_BlitSurface(sprite.surface, nullptr, surface, &rectangle);
        }
        
        /**
         * Blits the given sprite to this one.
         * The top-left corner of the given sprite is blitted to
         *   the coordinates of the given Point.
         * No scaling is performed.
         */
        void blit(const Sprite& sprite, const Point& point) noexcept {
            blit(sprite, point.get_x(), point.get_y());
        }
        
        /**
         * Blits the given sprite to this one.
         * The top-left corner of the given sprite is blitted to the
         *   coordinates of the top-left vertex of the given Rectangle.
         * No scaling is performed.
         */
        void blit(const Sprite& sprite, const Rectangle& rectangle) noexcept {
            blit(sprite, rectangle.get_point());
        }
        
        /**
         * Blits the given sprite to this one.
         * The centre of the given sprite is blitted in the
         *   given position.
         * The position is a ratio of the size of this sprite.
         * To blit to the centre, one should use 0.5 as x and y.
         * No scaling is perfomed.
         */
        void blit(const Sprite& sprite, double x, double y) noexcept {
            blit(
                sprite,
                static_cast<int>(surface->w * x - sprite.surface->w / 2),
                static_cast<int>(surface->h * y - sprite.surface->h / 2)
            );
        }
        //}
        
        /**
         * Returns the colour in RGB form.
         */
        static std::array<int, 3> to_rgb(Colour colour) noexcept {
            std::array<int, 3> rgb;
            
            switch (colour) {
                case BLACK:
                    rgb[0] = 0;
                    rgb[1] = 0;
                    rgb[2] = 0;
                    break;
                
                case RED:
                    rgb[0] = 0xff;
                    rgb[1] = 0;
                    rgb[2] = 0;
                    break;
                    
                case GREEN:
                    rgb[0] = 0;
                    rgb[1] = 0xff;
                    rgb[2] = 0;
                    break;
                    
                case BLUE:
                    rgb[0] = 0;
                    rgb[1] = 0;
                    rgb[2] = 0xff;
                    break;
                    
                case YELLOW:
                    rgb[0] = 0xff;
                    rgb[1] = 0xff;
                    rgb[2] = 0;
                    break;
                    
                case CYAN:
                    rgb[0] = 0;
                    rgb[1] = 0xff;
                    rgb[2] = 0xff;
                    break;
                    
                case MAGENTA:
                    rgb[0] = 0xff;
                    rgb[1] = 0;
                    rgb[2] = 0xff;
                    break;
                
                case WHITE:
                    rgb[0] = 0xff;
                    rgb[1] = 0xff;
                    rgb[2] = 0xff;
                    break;
                    
                case GREY:
                    rgb[0] = 0x7f;
                    rgb[1] = 0x7f;
                    rgb[2] = 0x7f;
                    break;
            }
            
            return rgb;
        }
        
    private:
        /**
         * Dynamically allocates a new surface with the given dimensions.
         * If a surface was already dynamically allocated, it is freed.
         */
        void create_surface(int width, int height) noexcept {
            destroy_surface();
            
            surface = SDL_CreateRGBSurface(
                0, width, height, SURFACE_DEPTH,
                SURFACE_MASKS[SPRITE_BYTE_ORDER][0], SURFACE_MASKS[SPRITE_BYTE_ORDER][1],
                SURFACE_MASKS[SPRITE_BYTE_ORDER][2], SURFACE_MASKS[SPRITE_BYTE_ORDER][3]
            );
            
            allocated = true;
        }
        
        /**
         * Destroys the surface if it was allocated.
         */
        void destroy_surface() noexcept {
            if (allocated) {
                SDL_FreeSurface(surface);
                allocated = false;
            }
        }
        
        static constexpr int SPRITE_BYTE_ORDER          // Byte ordering of the surface pixels.
            = SDL_BYTEORDER != SDL_BIG_ENDIAN; 
        static constexpr int SURFACE_DEPTH = 32;        // The number of bits per pixel.
        static constexpr Uint32 SURFACE_MASKS[2][4] = { // The position of bits for RGBA.
            {
                0xff000000,
                0x00ff0000,
                0x0000ff00,
                0x000000ff
            },
            {
                0x000000ff,
                0x0000ff00,
                0x00ff0000,
                0xff000000
            }
        };
        
        SDL_Surface* surface;   // The surface containing the pixel data of the sprite.
        bool allocated = false; // True if the surface's memory was allocated in this class.
};

/**
 * A class that manages the video system.
 * Each instance of this class corresponds with a window.
 * Instances of this class are not copiable, but are movable.
 */
class Display: public Sprite {
    public:
        // Constructors
        //{
        /**
         * Makes a window with the given dimensions and no title.
         * Passing 0 as both the width and height makes
         *   a "windowed fullscreen"-style window.
         */
        Display(int width = 0, int height = 0) noexcept:
            Sprite(nullptr)
        {
            if (!width && !height) {
                SDL_DisplayMode display_mode;
                SDL_GetDesktopDisplayMode(0, &display_mode);
                width = display_mode.w;
                height = display_mode.h;
            }
            
            create_window("", width, height, 0);
        }
        
        /**
         * Makes a window with the given title and dimensions.
         * Passing 0 as both the width and height makes
         *   a "windowed fullscreen"-style window.
         */
        Display(const std::string& title, int width = 0, int height = 0) noexcept:
            Sprite(nullptr)
        {
            if (!width && !height) {
                SDL_DisplayMode display_mode;
                SDL_GetDesktopDisplayMode(0, &display_mode);
                width = display_mode.w;
                height = display_mode.h;
            }
            
            create_window(title, width, height, 0);
        }
        
        /**
         * Makes a window with its dimensions being a ratio of the window size.
         * The window is titleless.
         */
        Display(double width, double height) noexcept:
            Sprite(nullptr)
        {
            SDL_DisplayMode display_mode;
            SDL_GetDesktopDisplayMode(0, &display_mode);
            
            create_window(
                "",
                width * display_mode.w,
                height * display_mode.h,
                0
            );
        }
        
        /**
         * Makes a window with its dimensions being a ratio of the window size.
         * The window has a title.
         */
        Display(const std::string& title, double width, double height) noexcept:
            Sprite(nullptr)
        {
            SDL_DisplayMode display_mode;
            SDL_GetDesktopDisplayMode(0, &display_mode);
            
            create_window(
                title,
                width * display_mode.w,
                height * display_mode.h,
                0
            );
        }
        
        /**
         * Constructs a new Display object from the given window.
         * The window is not destroyed when this object is destroyed
         *   and is the responsibility of the window's creator.
         * For this reason, this constructor is not recommended.
         */
        Display(SDL_Window* win) noexcept:
            Sprite(nullptr)
        {
            window = win;
            Sprite::operator=(SDL_GetWindowSurface(window));
        }
        
        /**
         * Display objects should not be copied.
         * Copying can cause the window to be destroyed prematurely or twice.
         */
        Display(const Display&) = delete;
        
        /**
         * Display objects can be moved safely.
         */
        Display(Display&& display) noexcept:
            Sprite(nullptr)
        {
            operator=(std::move(display));
        }
        //}
        
        /**
         * Destroys the window associated with the object if
         *   the memory for it was allocated by this object.
         * Frees the memory allocated to the Sprite object.
         */
        ~Display() noexcept {
            destroy_window();
        }
        
        // Assignment
        //{
        /**
         * Display objects should not be copied.
         * Copying can cause the window to be destroyed prematurely or twice.
         */
        Display& operator=(const Display&) = delete;
        
        /**
         * Display objects can be moved safely.
         */
        Display& operator=(Display&& display) noexcept {
            destroy_window();
            window = display.window;
            Sprite::operator=(std::move(static_cast<Sprite&&>(display)));
            window_allocated = display.window_allocated;
            display.window_allocated = false;
            
            return *this;
        }
        
        /**
         * Initialises the display with the given window.
         * The window is not destroyed when this object is destroyed
         *   and is the responsibility of the window's creator.
         * For this reason, this use of this method is not recommended.
         */
        Display& operator=(SDL_Window* win) noexcept {
            destroy_window();
            window = win;
            Sprite::operator=(SDL_GetWindowSurface(window));
            
            return *this;
        }
        //}
        
        /**
         * Updates the window's surface.
         */
        void update() noexcept {
            SDL_UpdateWindowSurface(window);
        }
        
        /**
         * Returns a reference to this
         *   object casted to a Sprite.
         * A legacy member function for when
         *   the display had a sprite member.
         */
        Sprite& get_sprite() noexcept {
            return *this;
        }
        
        /**
         * Returns a constant reference to
         *   this object casted to a Sprite.
         * A legacy member function for when
         *   the display had a sprite member.
         */
        const Sprite& get_sprite() const noexcept {
            return *this;
        }
        
        /**
         * Resizes the window.
         */
        void resize(int w, int h) noexcept {
            destroy_window();
            create_window(title, w, h, flags);
        }
        
        /**
         * Prevents the window from being resized except by explicit calls to resize().
         */
        void lock_size() noexcept {
            SDL_SetWindowResizable(window, SDL_FALSE);
        }
        
        /**
         * Allows the window to be resized.
         * This is the state of new windows.
         */
        void unlock_size() noexcept {
            SDL_SetWindowResizable(window, SDL_TRUE);
        }
        
    private:
        /**
         * Creates the window and its sprite.
         * Marks the window as self-allocated, which
         *   means that the window will be destroyed
         *   with this object.
         */
        void create_window(
            const std::string& title,
            int width,
            int height,
            Uint32 flags
        ) noexcept {
            this->title = title;
            this->flags = flags;
            window = SDL_CreateWindow(
                title.c_str(),
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                width,
                height,
                flags | DEFAULT_FLAGS
            );
            Sprite::operator=(SDL_GetWindowSurface(window));
            window_allocated = true;
        }
        
        /**
         * Destroys the window if the object allocated the memory for it.
         */
        void destroy_window() noexcept {
            if (window_allocated) {
                SDL_DestroyWindow(window);
                window_allocated = false;
            }
        }
        
        static constexpr Uint32 DEFAULT_FLAGS =
            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
        ; // The default window flags used for window creation.
        SDL_Window* window;            // The window for the display.
        bool window_allocated = false; // True if this class allocated memory for the window.
        std::string title;
        Uint32 flags;
};

/**
 * A class that manages the audio system.
 * Each instance of this class corresponds to an audio segment and device.
 * AudioThread contains an instance of this class and should be used instead for automatic queuing.
 */
class Audio {
    public:
        // Constructors
        //{
        /**
         * Loads an audio clip from the given source.
         * Can requeue whenever one wishes to do so.
         * The audio is unpaused by default.
         */
        Audio(const std::string& source) {
            load(source);
            SDL_PauseAudioDevice(audio_device, false);
        }
        
        /**
         * Loads an audio clip from the given source.
         * Stores the length of the song in seconds for requeuing.
         * The audio is unpaused by default.
         */
        Audio(const std::string& source, double l) {
            load(source);
            SDL_PauseAudioDevice(audio_device, false);
            length = l;
        }
        
        /**
         * Audio instances are not safe to be copied.
         */
        Audio(const Audio&) = delete;
        
        /**
         * Audio instances are safe to be moveed.
         */
        Audio(Audio&& audio) noexcept {
            operator=(std::move(audio));
        }
        //}
        
        /**
         * Frees all memory dynamically allocated to this object.
         */
        ~Audio() noexcept {
            free_audio();
        }
        
        // Assignment
        //{
        /**
         * Audio instances are not safe to be copied.
         */
        Audio& operator=(const Audio&) = delete;
        
        /**
         * Audio instances are safe to be moved.
         */
        Audio& operator=(Audio&& audio) noexcept {
            // Memory for this object is freed.
            free_audio();
            
            // Data is moved.
            audio_device = audio.audio_device;
            audio_buffer = audio.audio_buffer;
            audio_length = audio.audio_length;
            last_queue = audio.last_queue;
            length = audio.length;
            paused = audio.paused;
            last_pause = audio.last_pause;
            allocated = audio.allocated;
            
            // The given instance no longer frees its memory.
            audio.allocated = false;
            
            return *this;
        }
        //}
        
        // Audio Control
        //{
        /**
         * Sets the audio clip to play.
         * Manages the queue timer to account for the time paused.
         */
        void play() noexcept {
            if (paused) {
                last_queue += Timer::time() - last_pause;
                paused = false;
                SDL_PauseAudioDevice(audio_device, false);
            }
        }
        
        /**
         * Sets the audio clip to pause.
         * Stores the time of pausing.
         */
        void pause() noexcept {
            if (!paused) {
                SDL_PauseAudioDevice(audio_device, true);
                paused = true;
                last_pause = Timer::time();
            }
        }
        
        /**
         * Plays if the audio is paused.
         * Pauses if the audio is playing.
         */
        void pause_switch() noexcept {
            if (paused) {
                play();
            }
            
            else {
                pause();
            }
        }
        
        /**
         * Returns true if the audio is paused.
         */
        bool pause_check() const noexcept {
            return paused;
        }
        //}
        
        // Audio Queue
        //{
        /**
         * Queues the audio to play after the current audio clip stops playing.
         */
        void queue() noexcept {
            if (queuable()) {
                SDL_QueueAudio(audio_device, audio_buffer, audio_length);
                last_queue = Timer::time();
            }
        }
        
        /**
         * Clears the audio device's queue.
         * The audio will always be queuable after a call to this method.
         */
        void dequeue() noexcept {
            SDL_ClearQueuedAudio(audio_device);
            last_queue = 0;
        }
        
        /**
         * Returns true if the queue() method can queue audio.
         */
        bool queuable() const noexcept {
            return !last_queue || !length || Timer::time() > last_queue + length;
        }
        
        /**
         * A static method that constantly queues the audio passed.
         */
        static int thread_queue(void* data) noexcept {
            Audio& audio = *static_cast<Audio*>(data);
            
            while (!audio.pause_check()) {
                audio.queue();
            }
            
            return 0;
        }
        //}
        
    private:
        /**
         * Loads the song at the given source.
         */
        void load(const std::string& source) {
            SDL_AudioSpec audio_spec;
            
            if (!SDL_LoadWAV(source.c_str(), &audio_spec, &audio_buffer, &audio_length)) {
                throw std::runtime_error(SDL_GetError());
            }
            
            audio_device = SDL_OpenAudioDevice(nullptr, false, &audio_spec, nullptr, 0);
            allocated = true;
        }
    
        /**
         * Closes the associated audio device.
         * Frees the audio buffer.
         */
        void free_audio() noexcept {
            if (allocated) {
                SDL_CloseAudioDevice(audio_device);
                SDL_FreeWAV(audio_buffer);
            }
        }
    
        SDL_AudioDeviceID audio_device;
        Uint8* audio_buffer;
        Uint32 audio_length;
        double last_queue = 0;
        double length = 0;
        bool paused = false;
        double last_pause;
        bool allocated = false;
};

/**
 * A class that pairs the given Sprite with a Rectangle
 *   constructed for it.
 * The Sprite and Rectangle can be manipulated
 *   individually, but there a methods that use
 *   both objects in tandem.
 */
class Button {
    public:
        // Constructors
        //{
        /**
         * Constructs a new Button object from given copied Sprite.
         * The Rectangle is constructed at the given position
         *   and sets the dimensions to the sprite's dimensions.
         */
        Button(const Sprite& s, int x = 0, int y = 0) noexcept:
            sprite(s),
            rectangle(x, y, sprite.get_width(), sprite.get_height())
        {}
        
        /**
         * Constructs a new Button object from given moved Sprite.
         * The Rectangle is constructed at the given position
         *   and sets the dimensions to the sprite's dimensions.
         */
        Button(Sprite&& s, int x = 0, int y = 0) noexcept:
            sprite(std::move(s)),
            rectangle(x, y, sprite.get_width(), sprite.get_height())
        {}
        
        /**
         * Constructs a new Button object from the given copied Sprite.
         * The Rectangle is constructed with its dimensions set
         *   to the sprite's dimensions.
         * The Rectangle's position is set to mirror the effects
         *   of Sprite::blit(const Sprite&, double, double).
         */
        Button(
            const Sprite& s,
            const Sprite& stemplate,
            double x = 0.5,
            double y = 0.5
        ) noexcept:
            sprite(s),
            rectangle(
                stemplate.get_width() * x - sprite.get_width() / 2,
                stemplate.get_height() * y - sprite.get_height() / 2,
                sprite.get_width(),
                sprite.get_height()
            )
        {}
        
        /**
         * Constructs a new Button object from the given moved Sprite.
         * The Rectangle is constructed with its dimensions set
         *   to the sprite's dimensions.
         * The Rectangle's position is set to mirror the effects
         *   of Sprite::blit(const Sprite&, double, double).
         */
        Button(
            Sprite&& s,
            const Sprite& stemplate,
            double x = 0.5,
            double y = 0.5
        ) noexcept:
            sprite(std::move(s)),
            rectangle(
                stemplate.get_width() * x - sprite.get_width() / 2,
                stemplate.get_height() * y - sprite.get_height() / 2,
                sprite.get_width(),
                sprite.get_height()
            )
        {}
        //}
        
        /**
         * Blits the Button's sprite to the given sprite using
         *   the Button's Rectangle.
         */
        void blit_to(Sprite& s) const noexcept {
            s.blit(sprite, rectangle.get_x(), rectangle.get_y());
        }
        
        /**
         * Returns a reference to the button's sprite.
         */
        Sprite& get_sprite() noexcept {
            return sprite;
        }
        
        /**
         * Returns a constant reference to the button's sprite.
         */
        const Sprite& get_sprite() const noexcept {
            return sprite;
        }
        
        /**
         * Returns a reference to the button's rectangle.
         */
        Rectangle& get_rectangle() noexcept {
            return rectangle;
        }
        
        /**
         * Returns a constant reference to the button's rectangle.
         */
        const Rectangle& get_rectangle() const noexcept {
            return rectangle;
        }
    
    private:
        Sprite sprite;
        Rectangle rectangle;
};
//}

// Renderer Classes
//{
/**
 * An abstract base class for renderer subclasses to inherit from.
 * All renderers should be able to render a single line from a string input.
 */
class Renderer {
    public:
        /**
         * An enumeration for the justification in lined_render().
         */
        enum Justification {
            LEFT_JUSTIFY,
            CENTRE_JUSTIFY,
            RIGHT_JUSTIFY
        };
        
        /**
         * Returns a sprite that is a single line rendering of the passed string.
         * The size (in pixels) of the characters must be specified.
         */
        virtual Sprite render(const std::string&, int, int, int) const noexcept = 0;
        
        /**
         * Returns a sprite that is a single line rendering of the passed string.
         * The size (in pixels) of the characters must be specified.
         * Uses ratios of the given sprite to determine the character size.
         */
        Sprite render(
            const Sprite& ratio_base,
            const std::string& text,
            double width,
            double height,
            double separation = 0
        ) const noexcept {
            return render(
                text,
                width * ratio_base.width(),
                height * ratio_base.height(),
                separation * ratio_base.width()
            );
        }
        
        /**
         * Returns a sprite that is a multiple line rendering of the passed string.
         * The size (in pixels) of the characters must be specified.
         * The maximum width of the sprite and the space between lines can be defined.
         * The justification of the resulting sprite can be defined.
         */
        Sprite lined_render(
            const std::string& text,
            int width,
            int height,
            int x_separation = 0,
            int y_separation = 0,
            int max_width = 0,
            Justification justification = CENTRE_JUSTIFY
        ) const noexcept {
            // If the text is empty an empty sprite is returned.
            if (text != "") {
                // A string stream is used to split the text.
                // The string is appended with a new line to prevent
                //   an infinite loop with std::getline().
                std::stringstream stream(text + '\n');
                // New lines always split the text rendering.
                std::vector<std::string> text_lines;
                // Placeholder string.
                std::string string;
                
                // Each line is stored in the vector of text lines.
                for (
                    std::getline(stream, string);
                    !stream.eof();
                    std::getline(stream, string)
                ) {
                    text_lines.push_back(string);
                }
                
                // A vector of vectors of strings that represent each
                //   line that should be separately be rendered.
                std::vector<std::vector<std::string>> text_vectors;
                // The minimum number of lines to be rendered.
                int length = text_lines.size();
                
                // The vector of vectors of string is initialised.
                for (int i = 0; i < length; i++) {
                    // A new vector is added.
                    text_vectors.push_back(std::vector<std::string>());
                    
                    // The string is appended with a space to prevent
                    //   an infinite loop with std::getline().
                    stream.clear();
                    stream.seekg(0);
                    stream.str(text_lines[i] + ' ');
                    
                    for (
                        std::getline(stream, string, ' ');
                        !stream.eof();
                        std::getline(stream, string, ' ')
                    ) {
                        text_vectors[i].push_back(string);
                    }
                }
                
                // The maximum number of characters in a line.
                int max_characters = max_width / (width + x_separation);
                
                // The vector of vectors of strings is compressed.
                // If multiple strings are small enough to fit on
                //   one line, they are combined.
                for (int i = 0; i < length; i++) {
                    for (int j = 0; j < text_vectors[i].size() - 1; j++) {
                        if (
                            !max_characters ||
                            1 + text_vectors[i][j].length()
                            + text_vectors[i][j + 1].length()
                            <= max_characters
                        ) {
                            text_vectors[i][j] += ' ' + text_vectors[i][j + 1];
                            text_vectors[i].erase(text_vectors[i].cbegin() + j + 1);
                            // The string is checked again.
                            j--;
                        }
                    }
                }
                
                // The sprites for each lines are rendered.
                std::vector<Sprite> sprites;
                // The maximum length of the sprites.
                int true_width = 0;
                
                // The lines are rendered.
                for (int i = 0; i < length; i++) {
                    int length2 = text_vectors[i].size();
                    
                    for (int j = 0; j < length2; j++) {
                        sprites.push_back(render(
                            text_vectors[i][j],
                            width,
                            height,
                            x_separation
                        ));
                        int sprite_width = sprites.back().get_width();
                        
                        if (true_width < sprite_width) {
                            true_width = sprite_width;
                        }
                    }
                }
                
                // The full sprite is initialised for blitting to.
                length = sprites.size();
                Sprite sprite(true_width, length * (height + y_separation) - y_separation);
                
                // The position of the sprites is determined by the justification.
                int position;
                
                // The sprites are blitted onto a single sprite.
                for (int i = 0; i < length; i++) {
                    // The position is found.
                    switch (justification) {
                        // Centre justify.
                        case CENTRE_JUSTIFY:
                            position = (true_width - sprites[i].get_width()) / 2;
                            break;
                            
                        // Left justify.
                        case LEFT_JUSTIFY:
                            position = 0;
                            break;
                            
                        // Right justify.
                        case RIGHT_JUSTIFY:
                            position = true_width - sprites[i].get_width();
                            break;
                    }
                    
                    sprite.blit(sprites[i], position, i * (height + y_separation));
                }
                
                return sprite;
            }
            
            return Sprite();
        }
        
        /**
         * Returns a sprite that is a multiple line rendering of the passed string.
         * The size (in pixels) of the characters must be specified.
         * The maximum width of the sprite and the space between lines can be defined.
         * The justification of the resulting sprite can be defined.
         * Uses ratios of the given sprite to determine the character size.
         */
        Sprite lined_render(
            const Sprite& ratio_base,
            const std::string& text,
            double width,
            double height,
            double x_separation = 0,
            double y_separation = 0,
            double max_width = 0,
            Justification justification = CENTRE_JUSTIFY
        ) const noexcept {
            return lined_render(
                text,
                width * ratio_base.width(),
                height * ratio_base.height(),
                x_separation * ratio_base.width(),
                y_separation * ratio_base.height(),
                max_width * ratio_base.width(),
                justification
            );
        }
};

/**
 * A class that manages the rendering of the sprites of
 *   characters and numbers to other sprites.
 * The characters and numbers are monospaced and only
 *   capital numbers are available.
 */
template<int N = System::RENDERER>
class BasicRenderer: public Renderer {
    public:
        /**
         * Constructs a new Renderer object.
         * Sprites are created for each letter and number
         *   that has a source passed.
         * The sources should be an array of strings and the count
         *   should be the number of strings passed.
         * The array of sources should start with the letters
         *   in alphabetical order and then the numbers in
         *   ascending order (A-Z then 0-9).
         * The Boolean, numbers_first, indicates that the numbers
         *   come before the letters in the array.
         * An empty string can be used to not load a specific character.
         */
        BasicRenderer(
            const std::array<std::string, N>& sources,
            bool numbers_first = false
        ) noexcept {
            load_sprites(sources, N, numbers_first);
        }
    
        /**
         * Returns a sprite that is a rendering of the passed string.
         * The size (in pixels) of the characters must be specified.
         * The text is converted to uppercase.
         */
        Sprite render(
            const std::string& text,
            int width,
            int height,
            int separation = 0
        ) const noexcept override {
            int length = text.length();
            
            if (length) {
                Sprite rendering(length * (width + separation) - separation, height);
                
                for (int i = 0; i < length; i++) {
                    char character = text[i];
                    
                    // The character is converted to uppercase.
                    if ('a' <= character && character <= 'z') {
                        character -= 0x20;
                    }
                    
                    // A letter is rendered
                    if ('A' <= character && character <= 'Z') {
                        Sprite temporary(width, height);
                        temporary.blit(*letters[character - 'A']);
                        rendering.blit(temporary, i * (width + separation), 0);
                    }
                    
                    // A number is rendered
                    else if ('0' <= character && character <= '9') {
                        Sprite temporary(width, height);
                        temporary.blit(*numbers[character - '0']);
                        rendering.blit(temporary, i * (width + separation), 0);
                    }
                }
                
                return rendering;
            }
            
            return Sprite();
        }
        
    private:
        /**
         * Constructs sprites for the given characters.
         */
        void load_sprites(
            const std::array<std::string, N>& sources,
            int count,
            bool numbers_first
        ) noexcept {
            // Constructs the numbers first.
            if (numbers_first) {
                load_numbers(sources, 0, count);
                load_letters(sources, System::NUMBERS, count - System::NUMBERS);
            }
            
            // Constructs the letters first.
            else {
                load_letters(sources, 0, count);
                load_numbers(sources, System::LETTERS, count - System::LETTERS);
            }
        }
        
        /**
         * Constructs sprites for the given numbers.
         */
        void load_numbers(
            const std::array<std::string, N>& sources,
            int offset,
            int count
        ) noexcept {
            for (int i = 0; i < System::NUMBERS; i++) {
                // The sprite is loaded if the source was given.
                if (i < count && sources[i + offset] != "") {
                    numbers[i] = std::make_unique<Sprite>(sources[i + offset]);
                }
                
                // Else, an empty sprite is loaded.
                else {
                    numbers[i] = std::make_unique<Sprite>();
                }
            }
        }
        
        /**
         * Constructs sprites for the given letters.
         */
        void load_letters(
            const std::array<std::string, N>& sources,
            int offset,
            int count
        ) noexcept {
            for (int i = 0; i < System::LETTERS; i++) {
                // The sprite is loaded if the source was given.
                if (i < count && sources[i + offset] != "") {
                    letters[i] = std::make_unique<Sprite>(sources[i + offset]);
                }
                
                // Else, an empty sprite is loaded.
                else {
                    letters[i] = std::make_unique<Sprite>();
                }
            }
        }
        
        std::array<std::unique_ptr<Sprite>, System::LETTERS> letters;
        std::array<std::unique_ptr<Sprite>, System::NUMBERS> numbers;
};

/**
 * A class that manages the rendering of the
 *   sprites of characters to other sprites.
 * Any character can be rendered and the
 *   rendering is defined by the user.
 */
template<int N>
class FullRenderer: public Renderer {
    public:
        /**
         * Loads sprites for the given characters using the given sources.
         */
        FullRenderer(
            const std::array<char, N>& chars,
            const std::array<std::string, N>& sources
        ) noexcept {
            for (int i = 0; i < N; i++) {
                characters[i] = chars[i];
                sprites[i] = std::make_unique<Sprite>(
                    sources[i]
                );
            }
        }
        
        /**
         * Returns a sprite that is a rendering of the passed string.
         * The size (in pixels) of the characters must be specified.
         * Only characters that had a sprite loaded for them are rendered.
         */
        Sprite render(
            const std::string& text,
            int width,
            int height,
            int separation = 0
        ) const noexcept override {
            int length = text.length();
            
            if (length) {
                Sprite rendering(length * (width + separation) - separation, height);
                
                for (int i = 0; i < length; i++) {
                    char character = text[i];
                    int index = -1;
                    
                    // The character is searched for.
                    for (int j = 0; j < N; j++) {
                        if (character == characters[j]) {
                            index = j;
                        }
                    }
                    
                    // The character is rendered, if it was found.
                    if (index >= 0) {
                        Sprite temporary(width, height);
                        temporary.blit(*sprites[index]);
                        rendering.blit(temporary, i * (width + separation), 0);
                    }
                }
                
                return rendering;
            }
            
            return Sprite();
        }
    
    private:
        std::array<char, N> characters;                 // The renderable characters.
        std::array<std::unique_ptr<Sprite>, N> sprites; // The sprites for rendering.
};
//}

// Multithreading
//{
// Thread Primitives
//{
/**
 * Manages a separate thread of execution.
 * This is for use with 32-bit libraries, as they do not support std::thread.
 */
class Thread {
    public:
        /**
         * Constructs a thread object that is not associated with any thread.
         */
        Thread() noexcept {}
        
        /**
         * Creates a new thread of execution.
         * The thread calls the function passed, which should
         *   be of the type int function(void* data).
         * The data argument is the data that will be passed
         *   to the thread's function.
         */
        Thread(SDL_ThreadFunction function, void* data = nullptr) noexcept {
            new_thread(function, data);
        }
        
        /**
         * Instances of this class are not safe to copy.
         */
        Thread(const Thread&) = delete;
        
        /**
         * Instances of this class are safe to move.
         * Moving should be performed with care, as this thread must wait for
         *   its function to return before taking the value of the given thread.
         */
        Thread(Thread&& t) noexcept {
            operator=(std::move(t));
        }
        
        /**
         * If the thread has not returned by the end of this
         *   object's lifetime, it is waited for.
         */
        ~Thread() noexcept {
            wait();
        }
        
        /**
         * Instances of this class are not safe to copy.
         */
        Thread& operator=(const Thread&) = delete;
        
        /**
         * Instances of this class are safe to move.
         * Moving is not recommended, as the thread must
         *   for its function to return before taking the
         *   value of the given thread.
         */
        Thread& operator=(Thread&& t) noexcept {
            wait();
            thread = t.thread;
            t.thread = nullptr;
            
            return *this;
        }
        
        /**
         * Waits for the thread to return and returns its exit code.
         * If the thread is null, nothing happens and -1 is returned.
         */
        int wait() noexcept {
            int code = -1;
            
            if (thread) {
                SDL_WaitThread(thread, &code);
                thread = nullptr;
            }
            
            return code;
        }
    
        /**
         * Creates a new thread of exection when the
         *   last thread of exectution terminates.
         * Equivalent to using the move assignment operator
         *   with a temporary thread on the stack.
         */
        void new_thread(SDL_ThreadFunction function, void* data = nullptr) noexcept {
            wait();
            thread = SDL_CreateThread(function, nullptr, data);
        }
        
    private:
        SDL_Thread* thread = nullptr; // The thread of execution.
};

// Declaration for friendship declaration.
class ConditionVariable;

/**
 * An abstraction of the mutex thread primitive.
 */
class Mutex {
    // Condition variables are associated with a mutex when waiting.
    friend class ConditionVariable;
    
    public:
        /**
         * Creates a new unlocked mutex.
         * Throws an exception if the construction fails.
         */
        Mutex() {
            if (!(mutex = SDL_CreateMutex())) {
                throw std::runtime_error(SDL_GetError());
            }
        }
        
        /**
         * Destroys the mutex.
         * The mutex should have been unlocked before destruction.
         */
        ~Mutex() noexcept {
            destroy();
        }
        
        /**
         * Instances of this class are not safe to copy.
         */
        Mutex(const Mutex&) = delete;
        
        /**
         * Instances of this class are safe to move.
         */
        Mutex(Mutex&& m) noexcept {
            operator=(std::move(m));
        }
        
        /**
         * Instances of this class are not safe to copy.
         */
        Mutex& operator=(const Mutex&) = delete;
        
        /**
         * Instances of this class are safe to move.
         */
        Mutex& operator=(Mutex&& m) noexcept {
            destroy();
            mutex = m.mutex;
            m.mutex = nullptr;
            
            return *this;
        }
        
        /**
         * Locks the mutex.
         * Locks are recursive, so multiple locks by a single
         *   thread will require the same number of unlocks.
         * Locking a mutex locked by another thread will cause a block.
         * Throws an exception if the mutex could not be locked.
         */
        void lock() {
            if (SDL_LockMutex(mutex)) {
                throw std::runtime_error(SDL_GetError());
            }
            
            ++locks;
        }
        
        /**
         * Locks the mutex, if it is unlocked or the calling thread owns the lock.
         * Locks are recursive, so multiple locks by a single
         *   thread will require the same number of unlocks.
         * Locking a mutex locked by another thread will not cause a block.
         * Returns true if the mutex was locked, false if the lock is
         *   held by another thread, and throws an exception on error.
         */
        bool try_lock() {
            int status = SDL_TryLockMutex(mutex);
            
            if (!status) {
                ++locks;
                return true;
            }
            
            else if (status == SDL_MUTEX_TIMEDOUT) {
                return false;
            }
            
            else {
                throw std::runtime_error(SDL_GetError());
            }
        }
        
        /**
         * Attempts to unlock the mutex.
         * Throws an exception on error.
         * Throws an exception if the mutex was already unlocked.
         */
        void unlock() {
            if (!locks) {
                throw std::runtime_error("The mutex is not locked.");
            }
            
            --locks;
            
            if (SDL_UnlockMutex(mutex)) {
                throw std::runtime_error(SDL_GetError());
            }
        }
        
        /**
         * Returns the number of recursive locks on the mutex.
         */
        int count_locks() const noexcept {
            return locks;
        }
        
    private:
        /**
         * Destroys the mutex.
         * The mutex should have been unlocked before destruction.
         */
        void destroy() noexcept {
            if (mutex) {
                SDL_DestroyMutex(mutex);
            }
        }
        
        SDL_mutex* mutex; // The pointer to the raw mutex.
        int locks = 0; // The number of recursive locks made.
};

/**
 * An abstraction of the semaphore thread primitive.
 */
class Semaphore {
    public:
        /**
         * Creates a new mutex initialised with the given value.
         * Throws an exception if the construction fails.
         */
        Semaphore(Uint32 value) {
            if (!(semaphore = SDL_CreateSemaphore(value))) {
                throw std::runtime_error(SDL_GetError());
            }
        }
        
        /**
         * Destroys the semaphore.
         * The semaphore should not be waited on upon destruction.
         */
        ~Semaphore() noexcept {
            SDL_DestroySemaphore(semaphore);
        }
        
        /**
         * Instances of this class are not safe to copy.
         */
        Semaphore(const Semaphore&) = delete;
        
        /**
         * Instances of this class are safe to move.
         */
        Semaphore(Semaphore&& s) noexcept {
            operator=(std::move(s));
        }
        
        /**
         * Instances of this class are not safe to copy.
         */
        Semaphore& operator=(const Semaphore&) = delete;
        
        /**
         * Instances of this class are safe to move.
         */
        Semaphore& operator=(Semaphore&& s) noexcept {
            destroy();
            semaphore = s.semaphore;
            s.semaphore = nullptr;
            
            return *this;
        }
        
        /**
         * Waits for the semaphore to have a positive value and decrements it.
         * Throws an exception upon error.
         */
        void wait() {
            if (SDL_SemWait(semaphore)) {
                throw std::runtime_error(SDL_GetError());
            }
        }
        
        /**
         * Decrements the value of the semaphore if it is positive.
         * Returns true if the semaphore was decremented, false if the
         *   semaphore had a non-positive value, and throws with an error.
         * Does not wait for a positive value unlike wait().
         */
        bool try_wait() {
            int status = SDL_SemTryWait(semaphore);
            
            if (!status) {
                return true;
            }
            
            else if (status == SDL_MUTEX_TIMEDOUT) {
                return false;
            }
            
            else {
                throw std::runtime_error(SDL_GetError());
            }
        }
        
        /**
         * Waits for a given amount of time in milliseconds for the
         *   semaphore to have a positive value and decrements it.
         * Returns true if the semaphore was decremented, false if
         *   the semaphore timed out, and throws with an error.
         */
        bool timed_wait(Uint32 ms) {
            int status = SDL_SemWaitTimeout(semaphore, ms);
            
            if (!status) {
                return true;
            }
            
            else if (status == SDL_MUTEX_TIMEDOUT) {
                return false;
            }
            
            else {
                throw std::runtime_error(SDL_GetError());
            }
        }
        
        /**
         * Increments the semaphore's value and waits waiting threads.
         * Throws an exception upon error.
         */
        void post() {
            if (SDL_SemPost(semaphore)) {
                throw std::runtime_error(SDL_GetError());
            }
        }
        
        /**
         * Returns the current value of the semaphore.
         * Non-constant, as SDL_SemValue takes a non-constant pointer.
         */
        Uint32 get_value() noexcept {
            return SDL_SemValue(semaphore);
        }
        
    private:
        /**
         * Destroys the semaphore.
         * The semaphore should not be waited on upon destruction.
         */
        void destroy() noexcept {
            if (semaphore) {
                SDL_DestroySemaphore(semaphore);
            }
        }
        
        SDL_sem* semaphore; // The pointer to the raw semaphore.
};

/**
 * An abstraction of the condition variable thread primitive.
 */
class ConditionVariable {
    public:
        /**
         * Creates a new condition variable.
         * Throws if the condition variable could not be created.
         */
        ConditionVariable() {
            if (!(condition_variable = SDL_CreateCond())) {
                throw std::runtime_error(SDL_GetError());
            }
        }
        
        /**
         * Destroys the condition variable.
         */
        ~ConditionVariable() noexcept {
            destroy();
        }
        
        /**
         * Instances of this class are not safe to copy.
         */
        ConditionVariable(const ConditionVariable&) = delete;
        
        /**
         * Instances of this class are safe to move.
         */
        ConditionVariable(ConditionVariable&& cv) noexcept {
            operator=(std::move(cv));
        }
        
        /**
         * Instances of this class are not safe to copy.
         */
        ConditionVariable& operator=(const ConditionVariable&) = delete;
        
        /**
         * Instances of this class are safe to move.
         */
        ConditionVariable& operator=(ConditionVariable&& cv) noexcept {
            destroy();
            condition_variable = cv.condition_variable;
            cv.condition_variable = nullptr;
            
            return *this;
        }
        
        /**
         * Waits for the condition variable to be signalled.
         * The given locked mutex is temporarily unlocked while waiting.
         * Throws an exception upon error.
         */
        void wait(Mutex& mutex) {
            if (SDL_CondWait(condition_variable, mutex.mutex)) {
                throw std::runtime_error(SDL_GetError());
            }
        }
        
        /**
         * Waits for a given number of milliseconds for
         *   the condition variable to be signalled.
         * The given locked mutex is temporarily unlocked while waiting.
         * Returns true if the condition variable was signalled, false
         *   if the time ran out, and throws an exception upon error.
         */
        bool timed_wait(Mutex& mutex, Uint32 ms) {
            int status = SDL_CondWaitTimeout(condition_variable, mutex.mutex, ms);
            
            if (!status) {
                return true;
            }
            
            else if (status == SDL_MUTEX_TIMEDOUT) {
                return false;
            }
            
            else {
                throw std::runtime_error(SDL_GetError());
            }
        }
        
        /**
         * Signals one thread that is waiting on the condition variable.
         * Throws an exception upon error.
         */
        void signal() {
            if (SDL_CondSignal(condition_variable)) {
                throw std::runtime_error(SDL_GetError());
            }
        }
        
        /**
         * Signals all of the threads waiting on the condition variable.
         * Throws an exception upon error.
         */
        void broadcast() {
            if (SDL_CondBroadcast(condition_variable)) {
                throw std::runtime_error(SDL_GetError());
            }
        }
        
    private:
        /**
         * Destroys the condition variable.
         */
        void destroy() noexcept {
            if (condition_variable) {
                SDL_DestroyCond(condition_variable);
            }
        }
        
        SDL_cond* condition_variable; // The pointer to the raw condition variable.
};
//}

// Utility
//{
/**
 * A class for queuing audio in a separate thread of execution.
 * Publically inherits from Audio, but using Audio-specific functions is not recommended.
 */
class AudioThread: public Audio {
    public:
        /**
         * Loads Audio of a specified length and queues it continuously in another thread.
         */
        AudioThread(const std::string& source, double length):
            Audio(source, length),
            thread(Audio::thread_queue, this)
        {}
        
        /**
         * Explicit destructor to prevent an eternal Thread.wait().
         */
        ~AudioThread() noexcept {
            stop();
        }
        
        /**
         * Stops queuing the audio and clear's the audio's queue.
         */
        void stop() noexcept {
            pause();
            thread.wait();
            play();
            dequeue();
            stopped = true;
        }
        
        /**
         * Starts queuing the audio again.
         * If the music is already being queued, the queuing is restarted.
         */
        void start() noexcept {
            if (!stopped) {
                stop();
            }
            
            thread.new_thread(Audio::thread_queue, this);
        }
    
    private:
        Thread thread; // The thread in which the Audio is queued.
        bool stopped = false; // True if the audio has been stopped using this class.
};

/**
 * An abstract base class that allows a Messenger to receive messages in another thread.
 */
class MessengerThread: public virtual Messenger {
    public:
        /**
         * Waits for one message from the other messenger in another thread.
         * Resets the message to the given reset string.
         */
        void get_message() noexcept {
            message_string = message_reset;
            message_thread.new_thread(MessengerPackage::get_message, &messenger_package);
        }
        
        /**
         * Returns true if the message has been received from the other messenger.
         * This effectively checks if the message equates with its reset value.
         */
        bool received() const noexcept {
            return message_string != message_reset;
        }
        
        /**
         * Returns a constant reference to the message received.
         * Note that the message received will be at the
         *   reset value if the message was not yet received.
         */
        const std::string& message() const noexcept {
            return message_string;
        }
        
    protected:
        MessengerThread(
            const std::string& message_reset = "",
            int message_length = DEFAULT_READ,
            int padding = DEFAULT_PADDING,
            char padder = DEFAULT_PADDER
        ) noexcept:
            Messenger(padding, padder),
            messenger_package(*this, message_string, message_length),
            message_thread(),
            message_string(message_reset),
            message_reset(message_reset)
        {}
    
    private:
        MessengerPackage messenger_package; // Used for receiving messages in a thread.
        Thread message_thread; // The thread in which the message is received.
        std::string message_string; // The string where received messages are stored.
        std::string message_reset; // The string that indicates that the
                                   //   message has not been received yet.
};

/**
 * A class that allows for the Client to wait for messages in another thread.
 */
class ClientThread: public Client, public MessengerThread {
    public:
        /**
         * Constructs a ClientThread object that is fully initialised.
         */
        ClientThread(
            const std::string& address,
            int port,
            const std::string& message_reset = "",
            int message_length = DEFAULT_READ,
            int padding = DEFAULT_PADDING,
            char padder = DEFAULT_PADDER
        ):
            Client(address, port, padding, padder),
            MessengerThread(message_reset, message_length, padding, padder)
        {}
};

/**
 * A class that allows for the conditional construction of a Server instance.
 * Construction is managed in another thread and can be cancelled with a boolean signal.
 * Also allows for the Server to wait for messages in another thread.
 */
class ServerThread: public Server, public MessengerThread {
    public:
        /**
         * Constructs a ServerThread object by partially initialisation.
         * The Server is attempted to be constructed in another thread.
         * initialise() should be called periodically in the main
         *   thread to attempt to finish the initialisation.
         */
        ServerThread(
            int port,
            bool& cancel,
            const std::string& message_reset = "",
            int message_length = DEFAULT_READ,
            int padding = DEFAULT_PADDING,
            char padder = DEFAULT_PADDER
        ) noexcept:
            Server(),
            MessengerThread(message_reset, message_length, padding, padder),
            server_pointer(),
            server_package(server_pointer, cancel, port),
            server_thread(ServerPackage::make_server, &server_package)
        {}
        
        /**
         * If the server was successfully constructed, the
         *   object is initialised for use and true is returned.
         */
        bool initialise() noexcept {
            if (server_pointer) {
                server_thread.wait();
                Server::operator=(std::move(*server_pointer));
                server_pointer = nullptr;
                initialised = true;
            }
            
            return initialised;
        }
        
    private:
        std::unique_ptr<Server> server_pointer; // Used for delayed initialisation.
        ServerPackage server_package; // Used to construct the server in another thread.
        Thread server_thread; // The thread in which the construction is performed.
        bool initialised = false; // True if the object has been initialised.
};

/**
 * A class that allows for two messengers to act as a bridge for two other messengers.
 */
class BridgeThread: public Bridge {
    public:
        BridgeThread(
            const Messenger& source,
            const Messenger& destination,
            const std::string& terminator
        ) noexcept:
            Bridge(source, destination, terminator),
            bridge_thread(Bridge::make_bridge, this)
        {}
        
    private:
        Thread bridge_thread; // The thread in which the bridge is maintained.
};
//}
//}

/* CHANGELOG:
     v4.2:
       Added the Logger class.
       Added Events::set_clipboard() and Events::get_keyboard().
       Fixed Messenger::send() for length <= message.length().
       Messenger::DEFAULT_READ and DEFAULT_PADDING were reverted to 1000;
       Added Server::get_default_addresses().
       Added Display::lock_size() and Display::unlock_size().
       Used SDL_GetError() for multiple exception messages.
     v4.1.1.1:
       Commented on Event::wait() and Event::timed_wait(), explaining why Event::poll() should be used instead.
     v4.1.1:
       Added Events::start_keyboard() and Events::stop_keyboard().
     v4.1.0.1:
       Fixed Timer::time() to match the wall time in variable clock speed environments.
     v4.1:
       Added the RNG class.
     v4.0.3.1:
       Marked pure virtual method implementations with override.
     v4.0.3:
       Added Event::window_width() and Event::window_height().
       Display::resize() now takes two arguments (use the returned values of Event::window_*()).
     v4.0.2.1:
       Fixed Semaphore::destroy().
     v4.0.2:
       Mutex, Semaphore, and ConditionVariable can now only be moved, not copied.
     v4.0.1.3:
       Added a destructor to AudioThread.
     v4.0.1.2:
       Renamed Display::width to Display::width_ to avoid conflicts with Sprite::width().
       Renamed Display::height to Display::height_ to avoid conflicts with Sprite::height().
     v4.0.1.1:
       Improvements to documentation and sectioning.
     v4.0.1:
       Added the RESIZE Event::Type.
       Added the Display::resize() method.
       Added SDL_WINDOW_RESIZABLE to Display::DEFAULT_FLAGS.
     v4:
       Added the Event Class.
       Added the Mutex Class.
       Added the Semaphore Class.
       Added the ConditionVariable Class.
       Changed the value of Messenger::DEFAULT_READ from 1000 to 100.
       Slight modifications to documentation.
     v3.0.2:
       Added a Sprite source-loaded, ratio constructor.
       Random::get_real() and Random::get_double() now take doubles instead of ints.
       y_separation and max_width have swapped argument positions in Renderer::lined_render().
       System::VERSION is now defined to be of size System::VERSION_LENGTH.
       Exceptions from a missing source now display the source that is missing.
       SDL_WINDOW_RESIZABLE was removed from Display::DEFAULT_FLAGS.
       Improved documentation of functions overloads.
     v3.0.1.1:
       Messenger::send() no longer uses a loop to pad the message.
       Messenger::read() uses a vector instead of dynamically allocating a buffer.
       Improved comments in Messenger::send() and Messenger::read().
     v3.0.1:
       Sprite's constructors, that load a BMP from the given source,
         now throw an exception if the Surface could not be loaded.
       ServerThread::initialise() now resets server_thread and server_pointer.
     v3:
       Added the AudioThread class.
       Added the MessengerThread abstract base class.
       Added the ClientThread class.
       Added the ServerThread class.
       Added the BridgeThread class.
       ClientPackage was renamed to Bridge.
       Messenger::read() and Messenger::send() now throw an exception if the socket is null.
       Server and Client now virtually inherit from Messenger.
       Server and Client now have default constructors.
       Audio::load() and the Audio constructors now throw
         an exception if the audio file could not be found.
       Functions in the Random namespace now throw an exception if min > max.
       Display now has a set of default flags for window creation:
         SDL_WINDOW_SHOWN
         SDL_WINDOW_RESIZABLE
       Reversed the changelog's ordering.
     v2.1.0.1:
       Random::get_int() now converts (1 + max - min) to an unsigned integer.
     v2.1:
       Added the Random namespace.
       System::command now returns the command's exit code.
     v2:
       Added the MessengerPackage class.
       Added the ServerPackage class.
       Added the ClientPackage class.
       Moved BasicRenderer::LETTERS to System.
       Moved BasicRenderer::NUMBERS to System.
       Redefined System::RENDERER.
       Added some more scancode aliases to Events.
       BasicRenderer::render() and FullRenderer::render() no longer crash
         when passed an empty string with a non-zero separation.
       Server's constructor will now throw a runtime
         error if the port could not be opened.
       Server's constructor can now accept a constant boolean reference,
         and will throw a runtime error if the boolean's value is true.
       Added the Renderer::Justification enumeration.
       Renderer::lined_render() now takes a Justification as an argument,
         instead of an integer, for the justify parameter.
       The Thread class' constructor's data parameter is now optional.
       Added the Thread class' default constructor.
       Added the Thread::new_thread() method.
       Renderer::lined_render() is more efficient with empty strings.
       Added the Messenger::DEFAULT_READ constant expression.
       Added the Timer::HOURS_TO_MINUTES and
         Timer::MINUTES_TO_SECONDS constant expressions.
       Added the Timer::to_seconds constant expression function.
       Button's constructors now take a Sprite reference rather than a unique pointer.
       Button uses a Sprite rather than a unique pointer to one.
       Button uses a Rectangle rather than a unique pointer to one.
       Renderer::lined_render now supports strings
         with multiple spaces or new lines in a row.
       Messenger::send() now pads the sent string (to prevent
         Messenger::read() from reading 2 two messages at once).
       Display is now a subclass of Sprite, but all methods are still operational.
       Renderer::render() and Renderer::lined_render() now have ratio versions.
     v1.3.1:
       Added operator!=() to all classes with operator==().
       Rearranged the ordering of Sprite::Colour.
     v1.3:
       Added some new constructors for Rectangle.
       Added Rectangle::shift().
       Added Rectangle::widen().
       Generalised Circle Sprite::fill() methods to use Shape instances.
       Renamed Sprite::BYTE_ORDER to Sprite::SPRITE_BYTE_ORDER,
         in order to stop a name clash for some compilers.
     v1.2:
       System::initialise() now only takes a single argument of type Uint32.
       System::NET should be bitwise OR'd with
         other constants to intialise SDL Net.
       Sytem::NONE, System::VIDEO, System::AUDIO,
         and System::NET are now of type Uint32.
       Deleted the Server class' copy constructor and assignment operator.
       Deleted the Client class' copy constructor and assignment operator.
       Added the Server class' move constructor and assignment operator.
       Added the Client class' move constructor and assignment operator.
     v1.1.6:
       Added Audio::thread_queue().
     v1.1.5.1:
       Added #pragma once.
     v1.1.5:
       Added Sprite::to_rgb().
       Changed the relevant Sprite::fill() methods to use Sprite::to_rgb().
     v1.1.4:
       Added Audio::dequeue().
     v1.1.3:
       The constructor of the Client class can now throw,
         if the host address could not be resolved.
       System::info() is no longer prepended and terminated with a new line.
       Add the System::NONE and System::NET constant expressions.
       Sprite::operator=() now correctly returns the sprite.
     v1.1.2:
       Added Display constructors for ratios of the display size.
     v1.1.1:
       Moved Colour into Sprite.
       Added the Sprite copy constructor and assignment operator.
     v1.1:
       Renamed Renderer to BasicRenderer.
       Added the Renderer Abstract Base Class.
       BasicRenderer inherits from Renderer.
       Added the FullRenderer subclass of Renderer.
       Added the Renderer::lined_render() method.
       Renderer::render() can now optionally specify the
         separation between characters.
       Added GREY to Colour.
       Updated Sprite::fill() methods to use GREY.
     v1.0.1:
       Moved SDL_AND_NET_VERSION and SDL_AND_NET_VERSION_LENGTH to System.
       Renamed SDL_AND_NET_VERSION to VERSION.
       Renamed SDL_AND_NET_VERSION_LENGTH to VERSION_LENGTH.
       Moved LETTERS and NUMBERS to Renderer.
       Added the Point::click() and Point::unclick() methods.
       Changed the functionality of Shape::unclick() to be more intuitive.
       Added the System::RENDERER constant.
     v1.0.0.2:
       Fixed Point and Rectangle's integer constructors.
     v1.0.0.1:
       Fixed a typo in System::info().
     v1:
       Added default arguments to multiple class constructors.
       Added default arguments to some functions and methods.
       Display's constructors no longer produce fullscreen windows.
       Renderer now simply ignores invalid characters.
       All functions and methods have been marked as noexcept.
     v0.8.5:
       Made System::version() generic.
     v0.8.4:
       Added aliases for common scancodes in Events.
       Converted System::VIDEO and System::AUDIO to constant expressions.
       Converted Events::LEFT_CLICK, Events::MIDDLE_CLICK,
         and Events::RIGHT_CLICK to constant expressions.
     v0.8.3:
       Added the const version of Button::get_rectangle().
     v0.8.2:
       Added the Timer::cureent() function.
     v0.8.1:
       Added the Rectangle default constructor.
     v0.8:
       Restored the Thread class with no deprecation status.
       Made the Thread class non-copiable, but movable.
     v0.7:
       Removed the Thread class.
       Made Audio instances non-copiable, but movable.
       Added Audio::queuable().
     v0.6.7:
       Added the Rectangle::set() method that uses a sprite template.
     v0.6.6:
       Added a Sprite::blit() overload for Rectangle.
       Added the const version of Button::get_sprite().
     v0.6.5.1:
       Fixed Renderer::load_numbers() and Renderer::load_letters().
     v0.6.5:
       Changed the Renderer class to use std::array.
       Changed the Renderer class to be templated.
       Made Renderer::load_sprites() private.
       Added the const version of Display::get_sprite().
     v.0.6.4.3:
       Changed SDL_AND_NET_VERSION from const to constexpr.
       Changed Sprite::BYTE_ORDER from const to constexpr.
       Change Sprite::SURFACE_DEPTH from const to constexpr.
     v0.6.4.2:
       Added warnings for Events::unclick() and Shape::unclick().
     v0.6.4.1:
       Changed LETTERS and NUMBERS from macros to constant expressions.
     v0.6.4:
       Added the System::command() function.
     v0.6.3:
       Added the changelog.
     v0.6.2:
       Added Sprite::destroy_surface() and Display::destroy_window().
       Fixed a memory leak in move assignment and construction of Sprite and Display objects.
     v0.6.1.1:
       Fixed Renderer::render().
     v0.6.1:
       Changed the Sprite and Display classes to no longer be copiable.
     v0.6:
       Added the Renderer class.
     v0.5:
        Added the Shape, Circle, and Button classes.
        Made Rectangle a derived class of Shape.
        Moved Rectangle::click() and Rectangle::unclick() to Shape.
        Added the Circle overloads of the Sprite::fill() methods.
        Deprecated the Thread class.
     v0.4:
       Added the Thread class.
     v0.3.2:
       Added the System::version() and System::info() methods.
     v0.3:
       Added the Point and Rectangle classes.
       Changed Sprite::fill() from using SDL_Rect to using Rectangle.
     v0.2:
       Added the System, Timer, and Events namespaces.
       Renamed sdl_init() to initialised() and moved it to the System namespace.
       Renamed sdl_quit() to terminate() and moved it to the System namespace.
       Renamed get_time() to time() and moved to to the Timer namespace.
       Moved wait() to the Timer namespace.
     v0.1:
       Added the Messenger, Server, Client, Sprite, Display, and Audio classes.
       Added the Colour enumeration.
       Added the sdl_init(), sdl_quit(), get_time(), and wait() functions.
 */