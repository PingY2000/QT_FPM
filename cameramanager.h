//cameramanager.h
#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <QObject>
#include <QImage>
#include "toupcam.h"


class CameraManager : public QObject
{
    Q_OBJECT

public:
    explicit CameraManager(QObject *parent = nullptr);
    ~CameraManager();

    bool isOpen() const;

    void fetchImage();
    void snapImage();
    void fetchStillImage();
    void fetchStillImageTif();

    bool open();
    void close();

    void setAutoExposure(bool enabled);
    void put_ExpoTime(int Expotime);
    void put_ExpoGain(int ExpoGain);
    bool getExposureTime(unsigned& time_us);
    bool getGain(unsigned short &gain);

    void setSaveDirectory(const QString& dir);

    enum class ImageSource {
        Realtime,
        Snapshot
    };

    ImageSource lastImageSource = ImageSource::Realtime;

signals:
    void imageReady(const QImage& img);
    void imageArrived();
    void stillImageArrived();
    void exposureChanged();

private:
    HToupcam hcam = nullptr;
    QTimer* timer = nullptr;
    QString saveDirectory;

private slots:


    static void __stdcall EventCallback(unsigned nEvent, void* ctx);
};
#endif // CAMERAMANAGER_H
