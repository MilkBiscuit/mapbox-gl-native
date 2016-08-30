#include <mbgl/test/util.hpp>
#include <mbgl/test/stub_file_source.hpp>

#include <mbgl/style/style.hpp>
#include <mbgl/style/source_impl.hpp>
#include <mbgl/util/io.hpp>

using namespace mbgl;
using namespace mbgl::style;

TEST(Style, UnusedSource) {
    util::RunLoop loop;

    StubFileSource fileSource;
    Style style { fileSource, 1.0 };

    auto now = Clock::now();
    std::vector<std::string> classes;

    style.setJSON(util::read_file("test/fixtures/resources/style-unused-sources.json"));
    style.cascade(now, MapMode::Still, classes);
    style.recalculate(0, now, MapMode::Still);

    Source *usedSource = style.getSource("usedsource");
    EXPECT_TRUE(usedSource);
    EXPECT_TRUE(usedSource->baseImpl->isLoaded());

    Source *unusedSource = style.getSource("unusedsource");
    EXPECT_TRUE(unusedSource);
    EXPECT_FALSE(unusedSource->baseImpl->isLoaded());
}

TEST(Style, UnusedSourceActiveViaClassUpdate) {
    util::RunLoop loop;

    StubFileSource fileSource;
    Style style { fileSource, 1.0 };

    style.setJSON(util::read_file("test/fixtures/resources/style-unused-sources.json"));

    auto now = Clock::now();
    std::vector<std::string> classes = { "visible" };

    style.cascade(now, MapMode::Still, classes);
    style.recalculate(0, now, MapMode::Still);

    Source *unusedSource = style.getSource("unusedsource");
    EXPECT_TRUE(unusedSource);
    EXPECT_TRUE(unusedSource->baseImpl->isLoaded());

    // Style classes should be cleared upon new style load.
    style.setJSON(util::read_file("test/fixtures/resources/style-unused-sources.json"));

    now = Clock::now();
    classes.clear();

    style.cascade(now, MapMode::Still, classes);
    style.recalculate(0, now, MapMode::Still);

    unusedSource = style.getSource("unusedsource");
    EXPECT_TRUE(unusedSource);
    EXPECT_FALSE(unusedSource->baseImpl->isLoaded());
}

TEST(Style, Properties) {
    util::RunLoop loop;

    StubFileSource fileSource;
    Style style { fileSource, 1.0 };

    style.setJSON(R"STYLE({"name": "Test"})STYLE");
    ASSERT_EQ("Test", style.getName());

    style.setJSON(R"STYLE({"center": [10, 20]})STYLE");
    ASSERT_EQ("", style.getName());
    ASSERT_EQ((LatLng{20, 10}), style.getDefaultLatLng());

    style.setJSON(R"STYLE({"bearing": 24})STYLE");
    ASSERT_EQ("", style.getName());
    ASSERT_EQ((LatLng{0, 0}), style.getDefaultLatLng());
    ASSERT_EQ(24, style.getDefaultBearing());

    style.setJSON(R"STYLE({"zoom": 13.3})STYLE");
    ASSERT_EQ("", style.getName());
    ASSERT_EQ(13.3, style.getDefaultZoom());

    style.setJSON(R"STYLE({"pitch": 60})STYLE");
    ASSERT_EQ("", style.getName());
    ASSERT_EQ(60, style.getDefaultPitch());

    style.setJSON(R"STYLE({"name": 23, "center": {}, "bearing": "north", "zoom": null, "pitch": "wide"})STYLE");
    ASSERT_EQ("", style.getName());
    ASSERT_EQ((LatLng{0, 0}), style.getDefaultLatLng());
    ASSERT_EQ(0, style.getDefaultBearing());
    ASSERT_EQ(0, style.getDefaultZoom());
    ASSERT_EQ(0, style.getDefaultPitch());
}
