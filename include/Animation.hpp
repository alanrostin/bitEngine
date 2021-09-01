#ifndef Animation_hpp
#define Animation_hpp

#include <vector>

enum class FacingDirection
{
    None,
    Left,
    Right
};

struct FrameData
{
    int id;
    int x;
    int y;
    int width;
    int height;
    float displayTimeSeconds;
};

class Animation
{
    public:
        Animation(FacingDirection direction);
        void addFrame(int textureId, int x, int y, int width, int height, float frameTime);
        const FrameData* getCurrentFrame() const;
        bool updateFrame(float deltaTime);
        void reset();
        void setDirection(FacingDirection facingDirection);
        FacingDirection getDirection() const;
    
    private:
        void incrementFrame();
        std::vector<FrameData> frames;
        int currentFrameIndex;
        float currentFrameTime;
        FacingDirection direction;
};

#endif