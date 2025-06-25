// Copyright (C) 2011  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


// ----------------------------------------------------------------------------------------

std::string strip_path (
    const std::string& str,
    const std::string& prefix
)
{
    unsigned long i;
    for (i = 0; i < str.size() && i < prefix.size(); ++i)
    {
        if (str[i] != prefix[i]) 
            return str;
    }

    if (i < str.size() && (str[i] == '/' || str[i] == '\\'))
        ++i;

    return str.substr(i);
}

// ----------------------------------------------------------------------------------------

void make_empty_file (
    const std::string& filename
)
{
    std::ofstream fout(filename.c_str());
    if (!fout)
        throw ireclib::error("ERROR: Unable to open " + filename + " for writing.");
}

// ----------------------------------------------------------------------------------------

std::string to_png_name (const std::string& filename)
{
    std::string::size_type pos = filename.find_last_of(".");
    if (pos == std::string::npos)
        throw ireclib::error("invalid filename: " + filename);
    return filename.substr(0,pos) + ".png";
}

// ----------------------------------------------------------------------------------------

std::string to_jpg_name (const std::string& filename)
{
    std::string::size_type pos = filename.find_last_of(".");
    if (pos == std::string::npos)
        throw ireclib::error("invalid filename: " + filename);
    return filename.substr(0,pos) + ".jpg";
}

// ----------------------------------------------------------------------------------------

std::string to_jxl_name (const std::string& filename)
{
    std::string::size_type pos = filename.find_last_of(".");
    if (pos == std::string::npos)
        throw ireclib::error("invalid filename: " + filename);
    return filename.substr(0,pos) + ".jxl";
}

// ----------------------------------------------------------------------------------------

std::string to_webp_name (const std::string& filename)
{
    std::string::size_type pos = filename.find_last_of(".");
    if (pos == std::string::npos)
        throw ireclib::error("invalid filename: " + filename);
    return filename.substr(0,pos) + ".webp";
}

// ----------------------------------------------------------------------------------------

