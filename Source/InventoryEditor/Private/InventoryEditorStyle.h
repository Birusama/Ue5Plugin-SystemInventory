//Copyright(c) 2022, Viktor.F.P
#pragma once
#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"

#define IMAGE_BRUSH(RelativePath, ...) FSlateImageBrush(RootToContentDir(RelativePath, TEXT(".png")), __VA_ARGS__)

class FInventoryEditorStyle
	: public FSlateStyleSet
{
public:
	FInventoryEditorStyle()
		: FSlateStyleSet("InventoryEditorStyle")
	{
		const FVector2D Icon16x16(16.0f, 16.0f);
		const FVector2D Icon64x64(64.0f, 64.0f);

		if(FPaths::DirectoryExists(FPaths::ProjectPluginsDir() / TEXT("Inventory/Resources")))
			SetContentRoot(FPaths::ProjectPluginsDir() / TEXT("Inventory/Resources"));
		else if(FPaths::DirectoryExists(FPaths::ProjectPluginsDir() / TEXT("Runtime/Inventory/Resources")))
			SetContentRoot(FPaths::EnginePluginsDir() / TEXT("Runtime/Inventory/Resources"));
		else
			SetContentRoot(FPaths::EnginePluginsDir() / TEXT("Marketplace/Inventory/Resources"));

		Set("ClassIcon.ItemActor", new IMAGE_BRUSH("ItemActor_16x", Icon16x16));
		Set("ClassThumbnail.ItemActor", new IMAGE_BRUSH("ItemActor_64x", Icon64x64));
		
		Set("ClassIcon.InventoryComponent", new IMAGE_BRUSH("ComponentInventory_16x", Icon16x16));
		Set("ClassThumbnail.InventoryComponent", new IMAGE_BRUSH("ComponentInventory_64x", Icon64x64));

		FSlateStyleRegistry::RegisterSlateStyle(*this);
	}

	static FInventoryEditorStyle& Get()
	{
		static FInventoryEditorStyle Inst;
		return Inst;
	}

	~FInventoryEditorStyle()
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*this);
	}
};

#undef IMAGE_BRUSH