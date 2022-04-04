#include "CoreMinimal.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"

class FParseJson {
public:
	FParseJson(TSharedPtr<FJsonObject>jsonObject);
private:
	TSharedPtr<FJsonObject>Frames;
	TSharedPtr<FJsonObject>Bones;
};