#include "Animation.hpp"

Animation::Animation() : frames(0), currentFrameIndex(0), currentFrameTime(0.0f)
{

}

void Animation::addFrame(int textureId, int x, int y, int width, int height, float frameTime)
{
    FrameData frameData;
    frameData.id = textureId;
    frameData.x = x;
    frameData.y = y;
    frameData.width = width;
    frameData.height = height;
    frameData.displayTimeSeconds = frameTime;
    frames.push_back(frameData);
}

const FrameData* Animation::getCurrentFrame() const
{
    if (frames.size() > 0)
    {
        return &frames[currentFrameIndex];
    }

    return nullptr;
}

bool Animation::updateFrame(float deltaTime)
{
    if (frames.size() > 0)
    {
        currentFrameTime += deltaTime;

        if (currentFrameTime >= frames[currentFrameIndex].displayTimeSeconds)
        {
            currentFrameTime = 0.0f;
            incrementFrame();
            return true;
        }
    }

    return false;
}

void Animation::incrementFrame()
{
    currentFrameIndex = (currentFrameIndex + 1) % frames.size();
}

void Animation::reset()
{
    currentFrameIndex = 0;
    currentFrameTime = 0.0f;
}