import upload_sources from "./upload_sources";
function ProviderInfo({ info }) {
  return (
    <div>
      {Object.keys(info).map((key, index) => (
        <p key={index}>
          <strong>{key}: </strong>
          {key === "Privacy Policy" ? (
            <a href={info[key]} target="_blank">
              {info[key]}
            </a>
          ) : (
            ` ${info[key]}`
          )}
        </p>
      ))}
    </div>
  );
}
export default function UploadProvider({
  uploadProvider,
  setUploadProvider,
  setSingleFileOnly,
}) {
  function handleChange(e) {
    setUploadProvider(e.target.value);
    if (upload_sources[e.target.value].singleFileOnly) {
      setSingleFileOnly(true);
    }
  }
  return (
    <div>
      <label>
        Select upload provider:
        <select
          name="upload providers"
          onChange={handleChange}
          id="upload-providers"
        >
          <option value={upload_sources["file.io"]} defaultValue={true}>
            file.io
          </option>
        </select>
      </label>

      <div id="provider-info">
        <ProviderInfo info={upload_sources[uploadProvider].info} />
      </div>
    </div>
  );
}
/*
const uploadFile = async (e) => {
    const files = Array.from(e.target.files);
    const formData = new FormData();  

    const response = await fetch("https://file.io", {
        method: "POST",
        body: formData,
    });

    if (!response.ok) {
        throw new Error("Upload failed");
    }

    const data = await response.json();
    console.log(data)
    console.log(data.link); // This is the URL of the uploaded file
};
*/
